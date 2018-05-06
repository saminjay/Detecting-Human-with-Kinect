#include <SoftwareSerial.h>
char c;
int pwmL=A4;
int dirL=13;
int pwmR=A5;
int dirR=12;
SoftwareSerial BT(10,11);   // ( RX , TX )
void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(pwmL, OUTPUT);
  pinMode(dirL, OUTPUT);
  pinMode(pwmR, OUTPUT);
  pinMode(dirR, OUTPUT);

}
//-----------------------------------------------------------------------//  
void loop() {
  while (BT.available()>0){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  c = BT.read(); //Conduct a serial read
   
  
    BT.println(c); 

  
  if(c == '1') //forward
  {
    analogWrite(pwmL,250);
    digitalWrite (dirL,1);
    analogWrite(pwmR,250);
    digitalWrite(dirR,1);
  } 
  
  else if(c == '2') //stop
  {
    analogWrite(pwmL, 0);
    digitalWrite(dirL, 0);
    analogWrite(pwmR, 0);
    digitalWrite(dirR,0);
  }
  
  else if (c == '3') //right
  {
    analogWrite (pwmL,180);
    digitalWrite (dirL,1);
    analogWrite (pwmR,0);
    digitalWrite (dirR,0);  
  }
  
  else if ( c == '4') //left
  {
    analogWrite (pwmL,0);
    digitalWrite (dirL,0);
    analogWrite (pwmR,180);
    digitalWrite (dirR,1);
  }
 } 
}

void establishContact()
{
  while (BT.available() <= 0) {
    BT.println(c);   // send a capital A
    delay(10);
  }
}
