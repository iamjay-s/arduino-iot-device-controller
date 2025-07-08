# Arduino IoT Device Controller

This repository contains the embedded code for controlling various IoT hardware components using Arduino. These programs are designed to simulate real-world device behavior and act as the **edge layer** of a bidirectional IoT system.

> 🔧 This repo focuses on hardware control logic. The cloud-side data processing, analytics, and remote control logic are handled separately in a PySpark-based data pipeline (not included here).

---

## 🔍 Overview

This project serves as the **device-side logic** for an IoT pipeline, enabling the interaction between sensors (inputs) and actuators (outputs) like:

- 📟 **LCD Displays**
- 💡 **LEDs & Relays**
- 🔆 **LDR Sensors**
- 🎛️ **Potentiometers**
- ⚙️ **Servo Motors**
- 🧠 **Serial Monitor Input**
- 🌐 **WiFi-Based Actuation**

Each `.ino` file in the repo corresponds to a self-contained Arduino sketch demonstrating control logic and automation for a particular device or use case.

---

## 📁 Folder Structure

<pre> ``` ├── AurduinoWithPython/ # Arduino + Python interaction ├── AutomatedDoorLocking/ # Door locking via relay ├── BasicWiFiManager/ # WiFi manager logic ├── LCD/ # LCD display text ├── LCDAreaPerimeter/ # Area + perimeter calculator ├── LCDBasedVoltMeter/ # Voltage measurement on LCD ├── LDR/ # Basic LDR sensing ├── LDRControlledActuator/ # LDR triggering actuators ├── LEDOverWiFi/ # WiFi-controlled LED ├── PotentioMeter/ # Analog reading from potentiometer ├── PotentioMeter2/ # Extended potentiometer logic ├── PwdChecker/ # Password-protected logic ├── RelayOverWiFi1/ # Relay control over WiFi ├── RelayOverWiFi2/ # Variation with different logic ├── RelayWithToggleSwitch/ # Manual relay toggle ├── RelayWithToggleSwitchX2/ # Dual toggle switch control ├── SerialMonitorBasedRelayOp/ # Serial-triggered relay operation ├── ServoMotor/ # Control servo position ├── TiltSwitch/ # Tilt-based state trigger ├── TimerUpFrontToggle/ # Timed relay toggle └── ToggleSwitchOnOff/ # Basic on/off switch control ``` </pre>

## 🚀 Usage

### 🔌 Hardware Requirements

- Arduino Uno / Nano / ESP8266
- Breadboard, jumpers, resistors
- Relays, LDRs, potentiometers, LEDs, servo motors, etc.
- Optional: ESP module or WiFi-compatible board

### 🧪 Getting Started

1. Open any `.ino` file in the Arduino IDE.
2. Connect your Arduino board.
3. Upload the code.
4. Interact via sensors or serial monitor depending on the sketch.

---

## 🔄 Real-World Application

These sketches act as the **telemetry and actuation layer** for a full **bidirectional IoT system**:

- Devices **send sensor data** to a cloud data pipeline (e.g., Databricks, PySpark).
- Logic processed in the cloud triggers **remote control commands**.
- Arduino receives and executes these commands via serial, WiFi, or GPIO.

---

## 📦 Related Projects

> The data engineering and control decision-making part of this system is implemented using PySpark and Databricks, which is present within Azure Ecosystem.
