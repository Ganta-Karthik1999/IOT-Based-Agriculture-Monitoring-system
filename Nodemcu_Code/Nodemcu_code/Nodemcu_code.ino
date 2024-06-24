#include <SoftwareSerial.h>
#include "DHT.h"

#define BLYNK_TEMPLATE_ID "TMPL26P4yXMyi"
#define BLYNK_TEMPLATE_NAME "IOT Agriculture"
#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG

#include "BlynkEdgent.h"

#define DHTPIN D1  // Digital pin connected to the DHT sensor
#define LEDpin D2
#define obstaclePin A0
#define DHTTYPE DHT11  // DHT 11

DHT dht(DHTPIN, DHTTYPE);
int hasObstacle = LOW;  // LOW MEANS NO OBSTACLE

void checkDiseaseConditions(float t, float h) {
  if (t > 25 && t < 34 && h > 70 && h < 80) {
    Blynk.virtualWrite(V5, "Bacterial Blight");
    Blynk.virtualWrite(V10, "Add powdered coffee grounds");
  } else if (t > 24 && t < 28 and h > 90 and h < 100) {
    Blynk.virtualWrite(V5, "Rice Blast");
    Blynk.virtualWrite(V10, "Spray mixture of distilled water and baking soda");
  } else if (t > 20 and t < 25 and h > 70 and h < 90) {
    Blynk.virtualWrite(V5, "Powdery Mildew");
    Blynk.virtualWrite(V10, "Use fungicides and ensure good air circulation");
  } else if (t > 15 and t < 23 and h > 85 and h < 100) {
    Blynk.virtualWrite(V5, "Downy Mildew");
    Blynk.virtualWrite(V10, "Remove infected plants and apply appropriate fungicides");
  } else if (t > 10 and t < 25 and h > 70 and h < 100) {
    Blynk.virtualWrite(V5, "Late Blight");
    Blynk.virtualWrite(V10, "Use copper-based fungicides and remove infected plant parts");
  } else if (t > 20 and t < 25 and h > 80 and h < 100) {
    Blynk.virtualWrite(V5, "Anthracnose");
    Blynk.virtualWrite(V10, "Apply fungicides and ensure proper plant spacing");
  } else {
    Blynk.virtualWrite(V5, "No disease detected");
    Blynk.virtualWrite(V10, "Conditions normal");
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("Nodemcu is ready");
  pinMode(LEDpin, OUTPUT);
  pinMode(obstaclePin, INPUT);
  pinMode(10, OUTPUT);
  dht.begin();
  BlynkEdgent.begin();  // Initialize Blynk
}

void loop() {
  BlynkEdgent.run();  // Ensure Blynk runs properly

  if (Serial.available() > 0) {
    String soil = Serial.readStringUntil('\n');
    Serial.print("Received data: ");
    Serial.println(soil);

    int hasObstacle = digitalRead(obstaclePin);
    Serial.println(hasObstacle);

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }

    if (hasObstacle == 1) {
      Serial.println("HUMAN ALERT!!!!");
      Blynk.virtualWrite(V3, "Human Alert!!!!");
    } else {
      Serial.println("no Human alert!!!!");
      Blynk.virtualWrite(V3, "No human detected :)");
    }

    Blynk.virtualWrite(V1, t);
    Blynk.virtualWrite(V2, h);

    checkDiseaseConditions(t, h);
  }
}
