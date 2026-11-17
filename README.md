# 🌱 Plant Health Monitoring System

An IoT-based smart plant monitoring system using ESP32, soil moisture and light sensors, and the Blynk IoT platform. The system monitors environmental conditions, evaluates plant health using rule-based decision logic, and displays real-time readings on a mobile dashboard.

## 📌 Project Overview

The Plant Health Monitoring System is designed to help users monitor plant conditions remotely.

It uses an ESP32 microcontroller connected to sensors to collect environmental data. The collected readings are processed using predefined decision rules to identify whether a plant needs water or sunlight.

Sensor readings and plant health status are transmitted over Wi-Fi to the Blynk mobile application.

## ✨ Features

- Real-time soil moisture monitoring.
- Light intensity detection using an LDR sensor.
- Automatic moisture percentage calculation.
- Rule-based plant health classification.
- Healthy / Needs Water status.
- Healthy Light / Needs Sunlight status.
- Wireless monitoring through Blynk IoT.
- Live sensor readings through the Arduino Serial Monitor.

## 🛠️ Technologies & Components

### Hardware
- ESP32 Development Board
- Soil Moisture Sensor
- LDR (Light Dependent Resistor)
- Breadboard
- Jumper Wires
- USB Cable

### Software & Technologies
- Arduino IDE
- Embedded C++ / Arduino Programming
- Blynk IoT Platform
- Wi-Fi (WPA2-Enterprise / Eduroam)
- ESP32 Arduino Core

## 🔌 Pin Configuration

| Component | ESP32 GPIO |
|---|---|
| Soil Moisture Sensor (Analog) | GPIO 32 |
| LDR Sensor (Analog) | GPIO 34 |
| VCC | 3.3V |
| GND | GND |

**Note:** The LDR is connected through a voltage divider circuit. Both sensors must share a common GND with the ESP32.

## 📱 Blynk Dashboard Configuration

The project uses Blynk IoT to display sensor readings remotely.

| Virtual Pin | Data | Description |
|---|---|---|
| V0 | Moisture Percentage | Soil moisture level |
| V1 | Light Raw Value | LDR analog reading |
| V2 | Plant Status | Combined plant and light status |

### Dashboard Widgets
- Value Display – Soil Moisture
- Value Display – Light Intensity
- Label / Value Display – Plant Health Status

## ⚙️ Working Principle

1. The soil moisture sensor measures the moisture level in the soil.
2. The LDR sensor detects the surrounding light intensity.
3. ESP32 reads the analog sensor values.
4. Soil readings are converted into a percentage.
5. Predefined decision rules classify the plant condition.
6. ESP32 connects to Wi-Fi and communicates with Blynk Cloud.
7. Sensor readings and plant status are displayed on the mobile dashboard.

## 🧠 Plant Health Decision Logic

### Soil Moisture
The system uses calibrated dry and wet sensor readings:

- DRY = 3900
- WET = 1200

The moisture percentage is calculated using these reference values.

| Moisture Condition | Status |
|---|---|
| Above 50% | Healthy |
| 50% or Below | Needs Water |

### Light Detection

The LDR reading is compared with a predefined threshold:

| LDR Reading | Status |
|---|---|
| Below 2000 | Healthy Light |
| 2000 or Above | Needs Sunlight |

*Note: Sensor thresholds may require calibration depending on the sensor, circuit arrangement, and surrounding environment.*

## 🚀 Installation & Setup

1. Install Arduino IDE.
2. Install the ESP32 board package.
3. Install the Blynk library.
4. Connect the soil moisture sensor and LDR to the ESP32.
5. Open `Plant_Health_Monitoring_System.ino`.
6. Configure your Blynk Template ID, Template Name, and Auth Token.
7. Configure your Wi-Fi credentials.
8. Select the correct ESP32 board and COM port.
9. Upload the code to the ESP32.
10. Open the Blynk mobile application and monitor the readings.

**Important:** Keep your Wi-Fi credentials and Blynk Auth Token private. Never upload actual credentials to a public GitHub repository.

## 📂 Project Structure

```text
Plant_Health_Monitoring_System/
│
├── Plant_Health_Monitoring_System.ino
├── Plant Health Monitoring System.png
└── README.md
```

## ⚠️ Limitations

- Sensor readings may require calibration for better accuracy.
- LDR readings depend on the surrounding light and circuit configuration.
- Wi-Fi connectivity is required for remote monitoring.
- The current firmware implements soil moisture and light monitoring. Temperature and humidity monitoring using DHT11 is not yet integrated into this firmware.
- Automatic irrigation is not included in the current implementation.
- The decision logic is rule-based and does not use a trained machine learning model.

## 🔮 Future Improvements

- Integrate DHT11 for temperature and humidity monitoring.
- Add automatic irrigation using a relay and water pump.
- Implement mobile notifications for critical plant conditions.
- Improve sensor calibration and decision-making accuracy.
- Explore machine learning for more advanced plant health classification.

## 🎓 Academic Project

**Project:** Plant Health Monitoring System  
**Subject:** Artificial Intelligence  
**Department:** Computer Science / IT  
**University:** Sindh Madressatul Islam University

**Developed by:**
- Aashir Azeem
- Umama Amin
- Shiza Faisal

---

⭐ If you find this project interesting, consider giving this repository a star!
