
//download dht sensor library and adafruit unified library

#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT11 // can be changed if you choose DHT22
#define DHTPIN 33
#define mq_sensor 35

DHT dht(DHTTYPE , DHTPIN);

void setup()
{
  Serial.begin(115200);
  Serial.println("I`m ready to use 🥳🥳");

  //intialzing dht sensor 
  dht.begin();
  pinMode(mq_sensor , INPUT);
}
void loop()
{
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float gas_value = analogRead(mq_sensor);

  Serial.println("Temperature :");
  Serial.print(temperature);
  Serial.println("Humidity:");
  Serial.print(humidity);
  Serial.println("gas value:");
  Serial.print(gas_value);
  delay(5000);
}
