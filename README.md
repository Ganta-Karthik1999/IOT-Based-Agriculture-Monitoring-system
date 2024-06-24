Here's the updated README file with the enhanced functionality using the OpenCV code for soil moisture detection:

---

# IOT-Based-Agriculture-Monitoring-System

This project involves developing an IoT-based agriculture monitoring system that helps farmers monitor their fields remotely. The system uses various sensors to measure humidity, soil moisture, and water levels, transmitting data in real-time to a cloud platform.

## Introduction
This IoT-based agriculture monitoring system allows farmers to:
- Monitor soil moisture levels
- Track humidity and temperature
- Detect water levels
- View data in real-time on a cloud platform

## Features
- Real-time data monitoring
- Remote access to sensor data
- Alerts and notifications for critical conditions
- User-friendly dashboard for data visualization
-  Enhanced soil moisture detection using computer vision

## Components
- **NodeMCU (ESP8266)**
- **Arduino**
- **Soil Moisture Sensor**
- **Humidity and Temperature Sensor (DHT11/DHT22)**
- **Water Level Sensor**
- **Blynk App**
- **Raspberry Pi (for running OpenCV code)**

## Enhanced Functionality (New Integration)
- **Computer Vision-Based Soil Moisture Detection:** 
  - We have integrated an OpenCV code running on a Raspberry Pi to detect soil moisture levels based on the color of the soil. The system classifies soil as dry or wet and updates this data in real-time to enhance the overall monitoring capabilities.
  - The detected soil moisture levels are visualized on the user-friendly dashboard, providing a more comprehensive understanding of field conditions.
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
