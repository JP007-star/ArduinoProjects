char t;
 
void setup() {

pinMode(13,OUTPUT);//M1
pinMode(12,OUTPUT);//M2 
pinMode(11,OUTPUT);//M3
pinMode(10,OUTPUT);//M4
pinMode(9,OUTPUT);//M5
pinMode(8,OUTPUT);//M6
pinMode(7,OUTPUT);//M7
pinMode(6,OUTPUT);//M8
pinMode(5,OUTPUT);//M9
pinMode(4,OUTPUT);//M10
pinMode(3,OUTPUT);//en
pinMode(2,OUTPUT);//en

pinMode(A0,OUTPUT);//M11
pinMode(A1,OUTPUT);//M12
pinMode(A2,OUTPUT);//M13
pinMode(A3,OUTPUT);//M14   
pinMode(A4,OUTPUT);//en
pinMode(A5,OUTPUT);//en
  
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
digitalWrite(2,HIGH);
digitalWrite(3,HIGH);
digitalWrite(A4,HIGH);
digitalWrite(A5,HIGH);
 
 
if(t == 'A')//M1
{            
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  
}
else if(t == 'B')
{     
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
 
}

else if(t == 'C')
{     
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  
}
else if(t == 'D')
{     
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
}




else if(t == 'E')//M2
{     
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
 
}

else if(t == 'F')
{     
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
  
}
else if(t == 'G')
{     
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
else if(t == 'H')
{     
  digitalWrite(11,LOW);
  digitalWrite(10 ,LOW);
}






else if(t == 'I')//M3
{     
  digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
 
}

else if(t == 'J')
{     
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  
}
else if(t == 'K')
{     
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
}
else if(t == 'L')
{     
  digitalWrite(9,LOW);
  digitalWrite(8 ,LOW);
}





else if(t == 'M')//M4
{     
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
 
}

else if(t == 'N')
{     
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  
}
else if(t == 'O')
{     
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
}
else if(t == 'P')
{     
  digitalWrite(7,LOW);
  digitalWrite(6 ,LOW);
}



else if(t == 'Q')//M5
{     
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
 
}

else if(t == 'R')
{     
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  
}
else if(t == 'S')
{     
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
}
else if(t == 'T')
{     
  digitalWrite(5,LOW);
  digitalWrite(4 ,LOW);
}

else if(t== 'U')
{
  digitalWrite(A0,HIGH); 
  digitalWrite(A1,LOW);
  digitalWrite(A2,HIGH); 
  digitalWrite(A3,LOW); 
}
else if(t== 'V')
{
  digitalWrite(A0,LOW); 
  digitalWrite(A1,LOW);
  digitalWrite(A2,HIGH); 
  digitalWrite(A3,LOW); 
}
else if(t== 'W')
{
  digitalWrite(A0,HIGH); 
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW ); 
  digitalWrite(A3,LOW); 
}
else if(t== 'X')
{
  digitalWrite(A0,LOW); 
  digitalWrite(A1,HIGH);
  digitalWrite(A2,LOW); 
  digitalWrite(A3,HIGH); 
}

else if(t== 'Y')
{
  digitalWrite(A0,LOW); 
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW); 
  digitalWrite(A3,LOW); 
}
  
  


delay(100);
} 
