#include <FB_Const.h>
#include <FB_Error.h>
#include <FB_Network.h>
#include <FB_Utils.h>
#include <Firebase.h>
#include <FirebaseFS.h>
#include <Firebase_ESP_Client.h>

#include<WiFi.h>


//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

#define ssid "Networkchuck"
#define pass "inpbq2304"

int value = random(0,100);
unsigned long prevmills = 0;

#define db_url "https://example-4ca9b-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define apikey "AIzaSyAAWu2JuNu_bkdFb9QOIeNuLEB3Ys2vgp0"
bool signup = false;
// creating instances 
FirebaseData fbdo;  
FirebaseAuth auth;
FirebaseConfig config;

void wifisetup()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid , pass);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("connected !!!!");
  Serial.println(WiFi.localIP());
}
void setup()
{
  Serial.begin(115200);
  wifisetup();
  config.api_key = apikey; // assign api key to config api object 
  config.database_url = db_url;//assign realtime database url  to config database object

  //signup setup
  if(Firebase.signUp(&config ,&auth,"",""))
  {
    Serial.println("signup complete!!");
    signup = true;
  }
  else
  {
    Serial.println(config.signer.signupError.message.c_str());
  }

  config.token_status_callback = tokenStatusCallback;
  Firebase.reconnectWiFi(true);
  Firebase.begin(&config , &auth);

}



void loop()
{
  if(signup && Firebase.ready() && (millis()-prevmills >= 5000 || prevmills ==0))
  {
    prevmills = millis();
    Serial.println(value);
      if(Firebase.RTDB.setInt(&fbdo , "test/int" , value))
      {
        Serial.println("success");
      }
      else
      {
        Serial.println(fbdo.errorReason());
      }
      value = random(0,100);
  }
}