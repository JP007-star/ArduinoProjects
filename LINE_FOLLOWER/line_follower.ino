
void setup()
{
pinMode(13, INPUT);
pinMode(12, INPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
}
void loop()
{
if(digitalRead(13) && digitalRead(12)) // Move Forward
{
digitalWrite(11, HIGH);
digitalWrite(10, LOW);
digitalWrite(9, HIGH);
digitalWrite(8, LOW);
}
 
if(!(digitalRead(13)) && digitalRead(12)) // Turn right
{
digitalWrite(11, LOW);
digitalWrite(10, LOW);
digitalWrite(9, HIGH);
digitalWrite(8, LOW);
}
 
if(digitalRead(13) && !(digitalRead(12))) // turn left
{
digitalWrite(11, HIGH);
digitalWrite(10, LOW);
digitalWrite(9, LOW);
digitalWrite(8, LOW);
}
 
if(!(digitalRead(13)) && !(digitalRead(12))) // stop
{
digitalWrite(11, LOW);
digitalWrite(10, LOW);
digitalWrite(9, LOW);
digitalWrite(8, LOW);
}
}
