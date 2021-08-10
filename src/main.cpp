/**
 * @file main.cpp
 * @brief A reviever for LoRa data
 *
 */
#include "Preferences.h"
#include "TaskScheduler.h"
#include "WiFi.h"
#include "defines.h"
#include "lorahelpers.h"
#include "screen.h"
#include "string.h"
#include "wifisettings.h"

uint32_t packetCount = 0;
Scheduler runner;

// Task checkLoRa(0, TASK_FOREVER, &checkAndForwardPackets);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  runner.init();
  runner.addTask(wifi_connect_task);
  runner.addTask(wifi_watchdog_task);
  WiFi.mode(wifi_mode_t::WIFI_STA);
  WiFi.onEvent(_wifi_event);
  wifi_connect_task.enableDelayed(WIFI_CONNECT_INTERVAL);
  Serial.println("Initialized scheduler");
  Serial.begin(115200);
  while (!Serial) {
  }; // wait for serial
  Serial.println("Serial output initialized!");
  initLoRa(BAND, true);
  Serial.println("LoRa initialized!");
  displayInit();
  Serial.println("Display initialized!");
  displayLongString((char *)"Screen Initialized!");
}

void loop() {
  runner.execute();
  // Packet handling is *the* priority.
  checkAndForwardPackets();
}
