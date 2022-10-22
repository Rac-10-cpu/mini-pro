int lm1=8;
int lm2=9;
int rm1=10;
int rm2=11;

 void setup()
 {
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(3,INPUT);
  pinMode(2,INPUT);
 }
 // low is for white 
 // high is for black
void loop()
{
  int lsensor=digitalRead(3);
  int rsensor=digitalRead(2);
  if((lsensor==LOW)&&(rsensor==LOW))/// for forward
  {
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
  }
  else if((lsensor==HIGH)&&(rsensor==LOW))/// for turning right
  {
    digitalWrite(lm1,HIGH);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,HIGH);
    digitalWrite(rm2,LOW);
  }
  else if((lsensor==LOW)&&(rsensor==HIGH)) // for turning left
  {
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,HIGH);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,HIGH);
    
  }
  else ///to stop the car
  {
    digitalWrite(lm1,LOW);
    digitalWrite(lm2,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(rm2,LOW);
  }
}
