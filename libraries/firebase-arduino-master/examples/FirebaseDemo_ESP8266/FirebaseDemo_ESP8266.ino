
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


#define FIREBASE_HOST "ledstatus-7f1d8.firebaseio.com"
#define FIREBASE_AUTH "IwPvgbF0gFAPAGSIU3c6Fu3lsaGsrZuwigbvvWfl"

#define WIFI_SSID "Redmi"
#define WIFI_PASSWORD "Prasad66"

void setup() 
{
  
  Serial.begin(115200);
  pinMode (D0,OUTPUT);

 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
 
  
  while (WiFi.status() != WL_CONNECTED)
   {
    Serial.print(".");
    delay(500);
   }

   
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("ledstatus",0);
}

String n = 0;

void loop() {
  
  n=Firebase.getString("ledstatus");
  Serial.println(n);

  if (n=="true")
  {
    digitalWrite(D0,HIGH);
  }
  if(n=="false")
  {
    digitalWrite(D0,LOW);
  }
  
  
}
