#include <Servo.h>


int tl,tr,bl,br; //sensor value
int avt, avb,avl,avr; //average of sensor
int dvert, dhoriz; //difference of servo angle


Servo horizontal; 
int servoh = 90; // horiz default is 90 deg

Servo vertical; 
int servov = 90; // vertical default is 90 deg

int tol; // tolerance value

void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);

  Serial.begin(9600);
  horizontal.attach(9);
  vertical.attach(10);

  vertical.write(servov);
  horizontal.write(servov);
  delay(3000);

  tol=30;

}

void loop() {
  // put your main code here, to run repeatedly:

  readSensor(0);
  caldiff(1);
  
  trackingVertical();
  trackingHorizontal();
  delay(50);

  

}
void trackingVertical(){
  if (-1 * tol > dvert || dvert > tol) { // check if the diffirence is in the tolerance else change vertical angle
    if (avt < avb) {
      servov = ++servov;
      if (servov > 180) {
        servov = 180;
      }
    }
    else if (avt > avb) {
      servov = --servov;
      if (servov < 0) {
        servov = 0;
      }
    }
    vertical.write(servov);
  }
  
}

void trackingHorizontal(){
   if (-1 * tol > dhoriz || dhoriz > tol) {// check if the diffirence is in the tolerance else change horizontal angle
    if (avl > avr) {
      servoh = --servoh;
      if (servoh < 0) {
        servoh = 0;
      }
    }
    else if (avl < avr) {
      servoh = ++servoh;
      if (servoh > 180) {
        servoh = 180;
      }
    }
    else if (avl == avr) {
      // nothing
    }
    horizontal.write(servoh);
  }
}

void servoTest(){
  Serial.println("===========Set defualt  ============");
  vertical.write(90);
  horizontal.write(90);
  delay(2000);

  Serial.println("===========vertical test   ============");
  vertical.write(30);
  horizontal.write(90);
  delay(2000);

  vertical.write(140);
  horizontal.write(90);
  delay(2000);

  vertical.write(90);
  horizontal.write(90);
  delay(2000);

  Serial.println("===========horizontal test ============");
  vertical.write(90);
  horizontal.write(30);
  delay(2000);  
  vertical.write(90);
  horizontal.write(150);
  delay(2000); 
  vertical.write(90);
  horizontal.write(90);
  delay(2000); 
}

void readSensor(int verb){

  tl=analogRead(A0);
  tr=analogRead(A1);
  bl=analogRead(A2);
  br=analogRead(A3);
  if(verb){
    Serial.print("TL=");
    Serial.println(tl);
    Serial.print("TR=");
    Serial.println(tr);
    Serial.print("BL=");
    Serial.println(bl);
    Serial.print("BR=");
    Serial.println(br);
    Serial.println("=======================");
  }

}

void caldiff(int verb){
  avt = (tl + tr) / 2; // calculate Top average
  avb = (bl + br) / 2; // calculate bottom average
  avl = (tl + bl) / 2; // calculate Left average
  avr = (tr + br) / 2; // calculate Right average

  dvert = avt - avb; // diff between top and bottom
  dhoriz = avl - avr;// diff between Left and Right   

  if(verb){
    Serial.print("dvert=");
    Serial.println(dvert);
    Serial.print("dnoriz=");
    Serial.println(dhoriz);
    Serial.println("=======================");
  }  
}

