

#include<WiFi.h>
#define ssid "your wifi ssid"
#define pass "your wifi password"

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,pass);
  if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nconnected to : ");
  Serial.println(ssid);
  Serial.print("\nLocal IP address :");
  Serial.println(WiFi.localIP());
}
void loop()
{

}