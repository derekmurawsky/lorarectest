/**
 * @file lorahelpers.h
 * @brief Lora initializer
 * Some parts of this code were taken/adapted from
 * https://github.com/leedowthwaite/SimpleLoRaGateway/blob/master/LoRaInterface.ino
 * @date 2021-08-05
 */

/**
 * @brief Interrupt handler for recieving a LoRa packet
 *
 * @param packetSize The size of the recieved packet
 */
void onReceive(int packetSize);

/**
 * @brief Initializes LoRa radio
 * This function was pulled out of the Heltec library to allow finer grained
 * control of what was initialized when
 * @param band The band to be used
 * @param paboost Turns the power of the transmitter to maximum
 */
void initLoRa(long band, bool paboost);

/**
 * @brief This is the core function that checks for received LoRa packets and
 * forwards the contents on to MQTT
 */
void checkAndForwardPackets();

/**
 * @brief Get the chip ID of the chip
 * This function returns the chipID of the esp32
 * @see
 * https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series/blob/master/esp32/libraries/ESP32/examples/ChipID/GetChipID/GetChipID.ino
 */
void getChipID();