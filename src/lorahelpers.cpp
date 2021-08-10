/**
 * @file lorahelpers.h
 * @brief Lora initializer
 * Some parts of this code were taken/adapted from
 * https://github.com/leedowthwaite/SimpleLoRaGateway/blob/master/LoRaInterface.ino
 * @date 2021-08-05
 */

#include "CircularBuffer.h"
#include "SPI.h"
#include "defines.h"
#include "lora/LoRa.h"
#include "screen.h"

static String _payloadBuffer = "";

CircularBuffer<String, 10> recbuffer; // Recieve buffer to hold 10 packets

/**
 * @brief Interrupt handler for recieving a LoRa packet
 *
 * @param packetSize The size of the recieved packet
 */
static void onReceive(int packetSize) {
  // Keep this short and sweet - it's an interrupt service routine
  digitalWrite(LED_BUILTIN, HIGH);
  // Copy LoRa payload into buffer
  _payloadBuffer = "";
  while (LoRa.available()) {
    _payloadBuffer += (char)LoRa.read();
  }
  // Add it to the queue
  recbuffer.push(_payloadBuffer);
  digitalWrite(LED_BUILTIN, LOW);
}

/**
 * @brief Initializes LoRa radio
 * This function was pulled out of the Heltec library to allow finer grained
 * control of what was initialized when
 * @param band The band to be used
 * @param paboost Turns the power of the transmitter to maximum
 */
void initLoRa(long band, bool paboost) {
  SPI.begin(SCK, MISO, MOSI, SS);
  LoRa.setPins(SS, RST_LoRa, DIO0);
  if (!LoRa.begin(band, paboost)) {
    Serial.println("There was an issue initializing the LoRa radio.");
  };
  LoRa.setSyncWord(SYNCWORD);
  LoRa.onReceive(onReceive);
  LoRa.receive();
}

// checkAndForwardPackets()
// This is the core function that checks for received LoRa packets and forwards
// the contents on to MQTT
//
void checkAndForwardPackets() {
  // check for received
  if (recbuffer.size() > 0) {
    String rxPacketString = recbuffer.pop();
    char messageToDisplay[MAX_LORA_PAYLOAD + 50];
    // forward packet content to MQTT
    const char *msg = rxPacketString.c_str();
    // publishMQTT(msg);
    snprintf(messageToDisplay, sizeof(messageToDisplay),
             "Recieved packet: '%s' with RSSI %i", msg, LoRa.packetRssi());
    Serial.println(messageToDisplay);
    displayLongString(messageToDisplay);
  }
}

/**
 * @brief Get the chip ID of the chip
 * This function returns the chipID of the esp32
 * @see
 * https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series/blob/master/esp32/libraries/ESP32/examples/ChipID/GetChipID/GetChipID.ino
 */
void getChipID() {
  uint64_t chipId = 0;
  chipId = ESP.getEfuseMac(); // The chip ID is essentially its MAC
                              // address(length: 6 bytes).
  Serial.printf("ESP32ChipID=%04X",
                (uint16_t)(chipId >> 32));   // print High 2 bytes
  Serial.printf("%08X\n", (uint32_t)chipId); // print Low 4bytes.
}