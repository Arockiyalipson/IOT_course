
#define led_pin 2 // inbuilt led is connected to GPIO pin 2 of ESP32 

void setup() {
 Serial.begin(115200);
 Serial.println("hello buddies, welcome 😁😁"); 
 pinMode(led_pin , OUTPUT); // outputs from microcontroller
}

void loop() {
 digitalWrite(led_pin , LOW); // Logic 0
 delay(5000) ; // delay can be changed 1000micro sec = 1 sec
 digitalWrite(led_pin , HIGH); // Logic 1 
 delay(4000);
}
