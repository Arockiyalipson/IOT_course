
int led_pin = 2;
int PIR_pin = 34;

void setup()
{
  Serial.begin(115200);
  Serial.println("I`m alive 😎😎😎");
  pinMode(led_pin , OUTPUT);
  pinMode(PIR_pin , INPUT);
}
void loop()
{
  int pir_value = digitalRead(PIR_pin);
  Serial.println(pir_value);
  if(pir_value == 0)
  {
    digitalWrite(led_pin,LOW);
  }
  else
  {
    digitalWrite(led_pin,HIGH);
  }
  delay(5000);
}