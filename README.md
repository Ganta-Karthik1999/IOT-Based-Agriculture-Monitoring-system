Here's the updated README file with the enhanced functionality using the OpenCV code for soil moisture detection:

---

# IOT-Based-Agriculture-Monitoring-System

This project involves developing an IoT-based agriculture monitoring system that helps farmers monitor their fields remotely. The system uses various sensors to measure humidity, soil moisture, and water levels, transmitting data in real-time to a cloud platform.

## Introduction
This IoT-based agriculture monitoring system allows farmers to:
- Monitor soil moisture levels
- Track humidity, temperature, and pH levels
- Detect dry and wet land through camera-based detection
- Map real-time field data onto a dashboard using the Qt framework

## Features
- Real-time data monitoring
- Autonomous robot navigation through the farm
- Soil moisture detection using computer vision and mapping via Qt
- Remote access to sensor data
- Alerts and notifications for critical conditions
- User-friendly dashboard for data visualization

## Components
- **Raspberry Pi (running FreeRTOS for robot navigation and device drivers)**
- **Arduino**
- **Soil Moisture Sensor**
- **Humidity and Temperature Sensor (DHT11/DHT22)**
- **Water Level Sensor**
- **Blynk App**
- **Camera Module (for computer vision)**

## Enhanced Functionality (New Integration)
- **Computer Vision-Based Soil Moisture Detection:** 
  - The project now integrates a computer vision model running on a Raspberry Pi to detect soil moisture levels based on the color of the soil. A camera module attached to the robot captures images, and the system classifies soil as dry or wet in real-time.
  - The detected moisture levels are displayed on a Qt-based dashboard, with different colors representing dry and wet areas. The robot autonomously maps this data as it navigates the farm.
  
- **Data from Sensors:** In addition to soil moisture detection, the system collects humidity, temperature, and pH levels from various sensors. All data is sent to a server for further analysis and is available in real-time on the dashboard.


## Training Images
-The beloe are the test images used for Training the model.

![Train Image 1](https://drive.google.com/uc?id=1so0SUOcEQAiTMugqzvlKehHNdd_XMYTG)


![Train Image 2](https://drive.google.com/uc?id=1mSnT48SSiJFtpZJ6Tn69GGLHYghpDIn1)

## Testing Images

The below are the output of the soil moisture prediction.

![Test Image 1](https://drive.google.com/uc?id=1GTwGeOAivOTsde_4tHqpqj8A7si4-3t6)

![Test Image 1](https://drive.google.com/uc?id=1_iHUMszm0doyuQ5rGuAG8nvS_irnCu04)

![Test Image 1](https://drive.google.com/uc?id=1h-fvP7voM3HqUKbLOzPBejQk23cVu-gO)

![Test Image 1](https://drive.google.com/uc?id=1jN8djieeAfJhX0-Oh88ljD6v-SRrg6rL) 

![Test Image 1](https://drive.google.com/uc?id=1GTwGeOAivOTsde_4tHqpqj8A7si4-3t6) 

![Test Image 1](https://drive.google.com/uc?id=1vrJfoubLu5Gmv0Ogu2Ky1Skiwd78I5Jp) 

## Videos
The above are the videos of the earlier version of the project 
-Video 1: [Link to Project video ](https://drive.google.com/file/d/1CVZsW762TvaDzSrxwjRH8RlJ71gbA3Ju/view?usp=sharing) 
-Video 2: [Link to Project video ](https://drive.google.com/file/d/1NYSDULTSE9z-CgZLZ-26u0jvAZYNbWqh/view?usp=sharing) 


## Contact
For any inquiries or questions, please contact:
- **Name**: Karthik Ganta
- **Email**: ganta.k@northeastern.edu
