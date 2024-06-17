#define BLYNK_TEMPLATE_ID "TMPL26P4yXMyi"
#define BLYNK_TEMPLATE_NAME "IOT Agriculture"
#define BLYNK_AUTH_TOKEN "xfkJLEuq9s58Zrr2nNM38axZmkiteLPX"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>

SoftwareSerial myserial(D1, D2);
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "MadHouse";
char pass[] = "Mayhem@Madhouse";

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.virtualWrite(V1, "V1");
  Blynk.virtualWrite(V2, "V2");
  Blynk.virtualWrite(V3, "V3");
  Blynk.virtualWrite(V4, "V4");
  Blynk.virtualWrite(V5, "V5");
  String msg = myserial.readStringUntil('\r');
  Serial.println(msg);
  int finalobstrical = msg.substring(0, 1).toInt();
  int finalwatertest = msg.substring(1, 2).toInt();
  int finalhumidity = msg.substring(2, 4).toInt();
  int finaltemperature = msg.substring(7, 9).toInt();
  int finalsoil = msg.substring(12).toInt();;

  finalsoil = map(finalsoil, 0, 1023, 0, 100);

  if (finalobstrical == 0 or finalwatertest == 0 or finalhumidity == 0 or finaltemperature == 0) {
  }

  else {
    if (finalobstrical == 1) {
      Serial.println("HUMAN ALERT!!!!");
      Blynk.virtualWrite(V3, "Human Alert!!!!");
      Blynk.virtualWrite(V1, finalhumidity);
      Blynk.virtualWrite(V2, finaltemperature);
      Blynk.virtualWrite(V4, finalsoil);
      if (finaltemperature > 25 and finaltemperature < 34 and finalhumidity > 70 and finalhumidity < 80) {

        Blynk.virtualWrite(V5, "Bactrial Blight");
        Blynk.virtualWrite(V10, "Adding powered coffie grounds");
      }

      else if (finaltemperature > 24 and finaltemperature < 28 and finalhumidity > 90 and finalhumidity < 100) {

        Blynk.virtualWrite(V5, "Rice Blast");

        Blynk.virtualWrite(V10, "Spray Mixture of Distiller water and baking soda ");
      }

      else {
        Blynk.virtualWrite(V5, "No desesace Error");
        Blynk.virtualWrite(V10, "No precaution");
      }
    }

    else {
      Serial.println("no human alert!!!!");
      Blynk.virtualWrite(V3, "No human detected :)");
      Blynk.virtualWrite(V1, finalhumidity);
      Blynk.virtualWrite(V2, finaltemperature);
      Blynk.virtualWrite(V4, finalsoil);

      if (finaltemperature > 25 and finaltemperature < 34 and finalhumidity > 70 and finalhumidity < 90) {

        Blynk.virtualWrite(V5, "Bactrial Blight");
        Blynk.virtualWrite(V10, "Adding powered coffie grounds");
      }

      else if (finaltemperature > 24 and finaltemperature < 28 and finalhumidity > 90 and finalhumidity < 100) {

        Blynk.virtualWrite(V5, "Rice Blast");
        Blynk.virtualWrite(V10, "Spray Mixture of Distiller water and baking soda ");
      }

      else {
        Blynk.virtualWrite(V5, "No disease alert!!!!!");
        Blynk.virtualWrite(V10, "No precaution");
      }
    }
  }

  Serial.println(finalobstrical);
  Blynk.run();
}
