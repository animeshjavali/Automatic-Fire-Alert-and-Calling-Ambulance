
int smoke=29;
int PIR=28; 
int buzzer=10;
int readsmoke,readpir;
void setup()
{ 
  Serial.begin(9600);
  pinMode(smoke,INPUT);
  pinMode(PIR,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  pinMode(25,OUTPUT);

}

void loop()
{
  while(readsmoke<1000)
  {
    readsmoke=analogRead(smoke);
    digitalWrite(RED_LED,LOW); 
    digitalWrite(GREEN_LED,LOW); 
    Serial.print("Smoke value:");
    Serial.println(readsmoke);
    readpir=digitalRead(PIR);
    Serial.print("PIR value:");
    Serial.println(readpir);
    delay(500);
  }

  if(readpir==1)
  {
   digitalWrite(GREEN_LED,HIGH);
   digitalWrite(RED_LED,LOW);
   digitalWrite(buzzer,HIGH);  
   Serial.println("AT+CMGF=1");
   delay(5000);
   Serial.print("AT+CMGS=\"");
   Serial.print("8987******");
   Serial.println("\"");
   delay(2000);
   Serial.println("Fire at latitude:12.28 N longitude:76.64 E .First aid required since people are involved.");//Ambulance.
   Serial.write(0x1A);
   digitalWrite(buzzer,LOW);  
   delay(2000);
   Serial.println("AT+CMGF=1");
   delay(5000);
   Serial.print("AT+CMGS=\"");
   Serial.print("8987******");
   Serial.println("\"");
   delay(2000);
   Serial.print("Fire at latitude:12.28 N longitude:76.64 E.Please arrive immediately.");
   Serial.write(0x1A);
 while(1);
}
else if(readpir==0)
{
  digitalWrite(GREEN_LED,LOW);
  digitalWrite(RED_LED,HIGH);
  digitalWrite(buzzer,HIGH);//Half the intensity.
  Serial.println("AT+CMGF=1");
  delay(5000);
  Serial.print("AT+CMGS=\"");
  Serial.print("8987******");
  Serial.println("\"");
  delay(2000);
  Serial.println("Fire at latitude:12.28 N longitude:76.64 E .Please arrive immediately.");
  Serial.write(0x1A);
  digitalWrite(buzzer,LOW);  
  while(1);
  
}
}
