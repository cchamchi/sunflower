int tl,tr,bl,br; //sensor value
int avt, avb,avl,avr; //average of sensor
int dvert, dhoriz; //difference of servo angle
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);

  Serial.begin(9600);

  Serial.println("cds sensor test");
}

void loop() {
  // put your main code here, to run repeatedly:

  readSensor(1);

  caldiff(1);
 

  delay(1000);

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

