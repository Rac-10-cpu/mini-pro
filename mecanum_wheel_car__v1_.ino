#include<AFMotor.h>

AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
 
char command; 
 
void setup(){      
  Serial.begin(9600);  
}
void loop() {
  Serial.println(command);
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop();

    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    case 'G':
      forward_rightturn();
      break;
    case 'I':
      forward_leftturn();
      break;
    case 'H':
      backward_leftturn();
      break;
    case 'J':
      backward_rightturn();
      break;
    case 'q':
      rotate();
      break;
    }
  } 
}


void forward()
{
  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
  motor3.setSpeed(255);
  motor3.run(FORWARD); 
  motor4.setSpeed(255);
  motor4.run(FORWARD); 
}
 
void back()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(255); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(255); 
  motor4.run(BACKWARD); 
}
 
void left()
{
  motor1.setSpeed(125); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(125); 
  motor2.run(FORWARD); 
  motor3.setSpeed(125);
  motor3.run(BACKWARD);  
  motor4.setSpeed(125); 
  motor4.run(FORWARD); 
}
 
void right()
{
  motor1.setSpeed(125); 
  motor1.run(FORWARD); 
  motor2.setSpeed(125); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(125); 
  motor3.run(FORWARD); 
  motor4.setSpeed(125); 
  motor4.run(BACKWARD); 
} 

void forward_rightturn()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(125); 
  motor2.run(FORWARD); 
  motor3.setSpeed(125); 
  motor3.setSpeed(0); 
  motor3.run(RELEASE);
  motor4.run(125);
  motor4.run(FORWARD); 
}

void forward_leftturn()
{
  motor1.setSpeed(125); 
  motor1.run(FORWARD); 
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  motor3.setSpeed(125); 
  motor3.run(FORWARD); 
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
}

void backward_leftturn()
{
  motor1.setSpeed(125); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  motor3.setSpeed(125); 
  motor3.run(BACKWARD); 
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
}

void backward_rightturn()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(125); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(0); 
  motor3.run(RELEASE); 
  motor4.setSpeed(125); 
  motor4.run(BACKWARD); 
}

void rotate()
{
  motor1.setSpeed(125); 
  motor1.run(FORWARD); 
  motor2.setSpeed(125); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(125); 
  motor3.run(FORWARD); 
  motor4.setSpeed(125); 
  motor4.run(BACKWARD); 
}


void Stop()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  motor3.setSpeed(0); 
  motor3.run(RELEASE); 
  motor4.setSpeed(0); 
  motor4.run(RELEASE); 
}
