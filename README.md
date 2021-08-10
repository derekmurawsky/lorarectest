# Heltec WiFi Lora32 v2 Gateway

This is a simple LoRa reciever project based on the [Heltec Wifi Lora 32 v2](https://heltec.org/project/wifi-lora-32/). I wanted to learn about LoRa and low power sensors and this is the second project on that path. The first is the [LoRa Sensor Sender](https://github.com/derekmurawsky/LoRaSensorSender) project that sends data to this gateway.

I have a small homestead and wanted to monitor the temperature, pressure, humidity, and possibly light levels in my animal enclosures. The first prototype will go in my chicken coop and run.

Eventually I want to extend this project to support different sensors including soil moisture for our gardens and a general purpose weather station.

## ADRS

This project uses extremely abridged Architectural Decision Records for any major design decisions that I might question at a later date. They are in the [ADRS](/adrs/README.md) folder.

## ToDos

- [X] Add WiFi support
- [ ] Send data via MQTT in a sane way
- [X] Use TaskScheduler because it's awesome and a non-blocking(ish) way to go
- [ ] Refactor packet handler to use TaskScheduler with dynamic tasks.
- [ ] Add configuration support (capitve portal or some such?)

## Relevant Links

- [Adafruit BME280 Library](https://github.com/adafruit/Adafruit_BME280_Library) and [Example](https://learn.adafruit.com/adafruit-bme280-humidity-barometric-pressure-temperature-sensor-breakout/arduino-test)
- [ArduinoJSON](https://arduinojson.org/)
- [Heltec ESP32 Library](https://github.com/HelTecAutomation/Heltec_ESP32)
- [Heltec Wifi LoRa 32 v2 pinout diagram](assets/WIFI_LoRa_32_V2.pdf)
- [PlatformIO](https://platformio.org/) (Via [VSCode](https://code.visualstudio.com/))
- [leedowthwaite's Wonderful Github example of just this kind of thing](https://github.com/leedowthwaite/SimpleLoRaGateway)
- https://gist.github.com/evert-arias/d0abf2769802e56c88793a4447fe9f7e
- [Might be better to just use OpenMQTTGateway](https://github.com/1technophile/OpenMQTTGateway)
