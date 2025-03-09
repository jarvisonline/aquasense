# AquaSense

**AquaSense** is an AI-powered IoT system designed to monitor fish aquariums using real-time video processing, water quality sensors, and object detection models.

## 📌 Table of Contents
- [📖 Overview](#-overview)
- [✨ Features](#-features)
- [🔧 Hardware Components](#-hardware-components)
- [🛠 Software Stack](#-software-stack)
- [📥 Installation](#-installation)
- [🚀 Usage](#-usage)
- [📊 System Architecture](#-system-architecture)
- [🤝 Contributing](#-contributing)
- [📜 License](#-license)

## 📖 Overview
AquaSense enhances aquarium monitoring by automatically detecting fish motion, identifying species, and measuring key water parameters like pH and turbidity. The system streams video feeds to a web interface while analyzing fish behavior and water quality.

## ✨ Features
- 🐟 **Fish motion detection** using YOLOv5
- 🐠 **Fish species identification**
- 🌊 **Real-time water quality monitoring** (pH, Turbidity)
- 📹 **Live video streaming** via TCP
- 🌐 **Remote access through a web interface**
- ⚠️ **Alert system** for abnormal fish behavior or water quality

## 🔧 Hardware Components
- 🔹 **Raspberry Pi 3B Plus**
- 🔹 **Raspberry Pi Camera V2**
- 🔹 **pH Sensor with Module**
- 🔹 **Turbidity Sensor with Module**
- 🔹 **Power Supply**
- 🔹 **Jumper Wires**

## 🛠 Software Stack
- 🖥 **Raspberry Pi OS (64-bit)**
- 🐍 **Python**
- 🎯 **YOLOv5**
- 📷 **OpenCV**
- 🌐 **Flask (for web interface)**
- ✍️ **Thonny (IDE)**
- 🔗 **PuTTY (Remote Access)**

## 📥 Installation
### 🛠 1. Clone the repository:
```bash
git clone https://github.com/yourusername/aquasense.git
```
cd aquasense
# 🔌 Sensor Connection  
2. Connect sensors to the Raspberry Pi GPIO pins as per the circuit diagram.  

## 🚀 Usage  

### ▶️ Start the Flask web server:  
```bash
python app.py
```
### 🌍 Access the web interface:
``` bash
http://<raspberry_pi_ip>:5000
```
### 📡 Monitor fish motion, water quality, and view the live video feed.
#### 📊 System Architecture
[Camera] ---> [YOLOv5 Model] ---> [Web Interface]
               |                    
               v                    
       [Water Quality Sensors]  
### 🤝 Contributing
Contributions are welcome! Feel free to submit pull requests or report issues.

### 📜 License
This project is licensed under the MIT License.

This properly formats your markdown file with code blocks, headings, and structure. Let me know if you need further modifications! 🚀
