#include <LiquidCrystal.h>
LiquidCrystal lcd(8,7,6,5,4,3);
int gas=12;
int mot=11;
int temp=2;
int tem;
void setup()
{

Serial.begin(9600); 
pinMode(13, OUTPUT);
pinMode(12,INPUT);
pinMode(11,INPUT);
pinMode(10,OUTPUT);
pinMode(9,OUTPUT);
pinMode(A1,INPUT);
pinMode(2,OUTPUT);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("SMART ROOM");


}


void loop(){

gas= digitalRead(12);
mot= digitalRead(11);
temp=analogRead(2);
tem=temp-2;

Serial.println("Gas sensor"); 
Serial.println(gas);
Serial.println("MOTION sensor"); 
Serial.println(mot);
Serial.println("Room temperture"); 
Serial.println(temp);



lcd.setCursor(0,1);

lcd.print("TEMPATURE :");
lcd.print(tem);
lcd.print("C");
delay(100);


if (gas == HIGH){
digitalWrite(13,HIGH);
lcd.setCursor(0,1);
lcd.print("GAS LEAKAGE      ");
delay(100);
}
else{
digitalWrite(13,LOW);
lcd.print("                ");

}
if ( !digitalRead(A1))
{
  digitalWrite(2,LOW);
  
}
else
{
  digitalWrite(2,HIGH);
  lcd.setCursor(0,1);
  lcd.print("LIGHT IS ON   ");
  delay(100);
}


if (temp > (30)&& mot == HIGH) {
 
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  lcd.setCursor(0,1);
  lcd.print("FAN IS ON     ");
  delay(100);
  
  }

else
{
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  
}




delay(200); 
}
