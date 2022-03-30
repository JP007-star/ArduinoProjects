  /**
    *@description Function to IOT based Home Automation using NodeMCU 
    * @throws no exception
    * @author JayaPrasad.M <jayaprasad.m@avanzegroup.com>
    * @return String
    * @since 27 Mar 2021
    * @version Assignment
    *
**/
/*Importing of Header File*/
#include <ESP8266WiFi.h>     
#include <FirebaseArduino.h>
#include <SoftwareSerial.h>
SoftwareSerial s(D6,D1);
/*Defining of Constants */
#define Voltage          A0
#define Fan          D2
#define WaterPump    D3
#define Trigger      D4
#define Echo         D5
#define Lamp         D7
#define Ldr          D8

/*FireBase RealTime DataBase Setup*/
#define FIREBASE_HOST "homeautomation-79647-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "PAcQHnXsnP17rmTzCWMlkJ3m5ojAir8fVkXqKQQM"

/*Wifi Connection Credentials*/
#define WIFI_SSID "Jp"
#define WIFI_PASSWORD "Prasad66"
char data;
String CData; 
String FanStatus;
String LampStatus;
String WaterPumpStatus;
String TemperatureStatus;
String CurrentStatus;
String VoltageStatus;
String WaterLevelStatus;
String RoomLightStatus;





long Duration;
int WaterLevel=0;
int LdrStatus;

void setup() {
  s.begin(9600);
  Serial.begin(9600);
  
  

  /*I/P Pin Configuration*/
 
  pinMode(Ldr, INPUT);
  pinMode(Voltage, INPUT);
  pinMode(Fan, OUTPUT);
  pinMode(Lamp, OUTPUT);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(WaterPump, OUTPUT);

  /*Wifi Connection Verfication*/
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED){
  Serial.print(".");
  delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  /*Firebase Initialisation*/  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

 
}

void loop() {
  s.write("s");
  if (s.available()>0)
  {
    data=s.read();
    CData = CData+ data; 
     if( data == '\n')
    {
 TemperatureStatus = getValue(CData, ',', 0);
 VoltageStatus= getValue(CData, ',', 1);
 CurrentStatus = getValue(CData, ',', 2);
CData = ""; 
    }
  }

  /*  Getting FireBase Json Value From RealTime DataBase as String */
  FanStatus=Firebase.getString("Fan");
  LampStatus=Firebase.getString("Lamp");
  WaterPumpStatus=Firebase.getString("WaterPump");
  RoomLightStatus=Firebase.getString("Room Light");

  /* Getting WaterLevel from UltraSonic Sensor */
  // Clears the Trigger
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);

  // Sets the Trigger on HIGH state for 10 micro seconds
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  // Reads the Echo, returns the sound wave travel time in microseconds
  Duration = pulseIn(Echo, HIGH);

  // Calculating the distance
  WaterLevel= Duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Water Level: ");
  Serial.println(WaterLevel);
 
  
  /*   Sending RealTimeData Fetch from Sensor to  DataBase  */

  WaterLevelStatus =String(WaterLevel);
  LdrStatus = digitalRead(Ldr);
  if(LdrStatus==1)
  {
    Firebase.setString("Room Light","Dark");
  }
  if(LdrStatus==0){
    Firebase.setString("Room Light","Light");
  }
  
  Firebase.setString("Room Temperature",TemperatureStatus);
  Firebase.setString("Voltage",VoltageStatus);
  Firebase.setString("Current",CurrentStatus);
  Firebase.setString("Water Level",WaterLevelStatus);
  
  
  Serial.println("Room Temperature"+TemperatureStatus);
  Serial.println("Voltage"+VoltageStatus);
  Serial.println("Current"+CurrentStatus);
  Serial.println("Fan is"+FanStatus);
  Serial.println("Lamp is"+LampStatus);
  Serial.println("WaterPump is"+WaterPumpStatus);
  Serial.println("Room Light is"+RoomLightStatus);

  
  /*  Optimizing the  System According to RealTimeData  */
  if (FanStatus=="ON"){
    digitalWrite(Fan,HIGH);
    Serial.println("Fan is"+FanStatus);
  }
  else
  {
    digitalWrite(Fan,LOW);
    Serial.println("Fan is"+FanStatus);
  }
 
  if(LampStatus=="ON"||RoomLightStatus=="DARK"){
    digitalWrite(Lamp,HIGH);
    Serial.println("Lamp is"+LampStatus);
  }
  else
  {
    digitalWrite(Lamp,LOW);
    Serial.println("Lamp is"+LampStatus);
  }
  
  if(WaterPumpStatus=="ON"){
    if(WaterLevel > 10)
    {
    digitalWrite(WaterPump,HIGH);
    Serial.println("WaterPump is"+WaterPumpStatus);
    }
    else
    {
    digitalWrite(WaterPump,LOW);
    Serial.println("WaterPump is"+WaterPumpStatus);
    }
  }
  else
  {
    digitalWrite(WaterPump,LOW);
    Serial.println("WaterPump is"+WaterPumpStatus);
  }

  

delay(1000); 
}
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
