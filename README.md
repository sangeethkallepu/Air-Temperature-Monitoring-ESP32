# Air & Temperature Monitoring System Using ESP32

## Overview

This project is an IoT-based Air Quality and Temperature Monitoring System developed using ESP32. The system continuously monitors environmental conditions using the MQ135 Air Quality Sensor and DHT11 Temperature & Humidity Sensor. Sensor data is displayed on an LCD screen, transmitted to the Blynk mobile application for remote monitoring, and alerts users through a buzzer and Gmail notifications when unsafe conditions are detected.

## Features

- Real-time air quality monitoring
- Real-time temperature and humidity monitoring
- LCD display for local monitoring
- Remote monitoring through the Blynk mobile application
- Buzzer alert for abnormal conditions
- Gmail notifications for threshold violations
- Wi-Fi-enabled IoT connectivity using ESP32
- Continuous environmental monitoring

## Components Used

- ESP32 Development Board
- MQ135 Air Quality Sensor
- DHT11 Temperature and Humidity Sensor
- 16x2 LCD Display (I2C)
- Buzzer
- Breadboard
- Jumper Wires
- USB Cable
- Wi-Fi Network
- Blynk IoT Platform

## System Architecture

```text
MQ135 Sensor      DHT11 Sensor
      │                 │
      └───────┬─────────┘
              │
            ESP32
              │
    ┌─────────┼─────────┐
    │         │         │
    ▼         ▼         ▼
  LCD      Blynk      Gmail
Display     App       Alerts
              │
              ▼
           Buzzer
```

## Working Principle

1. The MQ135 sensor measures air quality levels.
2. The DHT11 sensor measures temperature and humidity.
3. ESP32 collects and processes sensor data.
4. Current readings are displayed on the LCD screen.
5. Data is sent to the Blynk mobile application through Wi-Fi.
6. When sensor readings exceed predefined threshold values:
   - The buzzer activates to provide an audible alert.
   - A notification is sent through the Blynk app.
   - A Gmail alert is sent to the registered email address.
7. Users can monitor environmental conditions locally and remotely in real time.

## Project Structure

```text
Air-Temperature-Monitoring-ESP32/
│
├── ESP32_Code/
│   └── air_temperature_monitoring.ino
│
├── Circuit_Diagram/
│   └── circuit_diagram.png
│
├── Images/
│   ├── setup.jpg
│   ├── lcd_display.jpg
│   └── output.jpg
│
└── README.md
```

## Installation

1. Clone the repository:


2. Open the project in Arduino IDE.

3. Install the required libraries:
   - Blynk Library
   - DHT Sensor Library
   - Adafruit Unified Sensor Library
   - LiquidCrystal I2C Library

4. Configure:
   - Blynk Authentication Token
   - Wi-Fi SSID
   - Wi-Fi Password
   - Gmail Alert Settings

5. Select the ESP32 board and upload the code.

6. Open the Serial Monitor and Blynk App to monitor data.

## Sample Output

```text
Temperature : 29°C
Humidity    : 68%
Air Quality : 185 PPM
Status      : GOOD 
```

## Results

- Successfully monitored air quality, temperature, and humidity.
- Displayed sensor readings on the LCD screen.
- Sent real-time data to the Blynk mobile application.
- Activated buzzer alerts for unsafe conditions.
- Generated Gmail notifications when threshold values were exceeded.

## Applications

- Smart Home Monitoring
- Indoor Air Quality Monitoring
- Environmental Monitoring
- Industrial Safety Systems
- Smart Building Automation
- IoT-Based Research Projects

## Future Enhancements

- Cloud database integration
- Historical data logging and analytics
- Mobile push notifications
- Multiple gas sensor support
- AI-based environmental prediction
- Web dashboard for monitoring

## Author

Sangeeth Kallepu
