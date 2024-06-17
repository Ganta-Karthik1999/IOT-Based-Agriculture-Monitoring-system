
#include "DHT.h"

#define DHTPIN 4 // Digital pin connected to the DHT sensor
#define LEDpin 7
#define obstaclePin A0
#define DHTTYPE DHT11 // DHT 11
#define waterpin

DHT dht(DHTPIN, DHTTYPE);
int hasObstacle = LOW; // LOW MEANS NO OBSTACLE

void setup()
{
  Serial.begin(9600);

  pinMode(LEDpin, OUTPUT);
  pinMode(obstaclePin, INPUT);
  pinMode(waterpin, INPUT);
  pinMode(10, OUTPUT);
  dht.begin();
}

void loop()
{
  // Obstrical pin will check if the obstrical exist or not
  hasObstacle = digitalRead(obstaclePin);

  // The Water pin will send the analog value via the analog pins
  int waterobs = analogRead(waterpin);

  //
  if (hasObstacle == LOW)
  {
    Serial.print("1");
    digitalWrite(LEDpin, HIGH);
  }
  else
  {
    Serial.print("2");
    digitalWrite(LEDpin, LOW);
  }
  else if (waterobs == HIGH)
  {

    Serial.print("3");
    digitalWrite(10, HIGH);
  }
  else
  {
    Serial.print("4");
    digitalWrite(10, LOW);
  }

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  // Serial.print(F("Humidity: "));
  Serial.print(h);
  // Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(waterobs);
  // Serial.println(F("°C "));
  delay(2000);
}
