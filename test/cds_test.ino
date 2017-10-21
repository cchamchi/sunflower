int tl;
int tr;
int bl;
int br;

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

  tl=analogRead(A0);
  tr=analogRead(A1);
  bl=analogRead(A2);
  br=analogRead(A3);
  Serial.print("TL=");
  Serial.println(tl);
  Serial.print("TR=");
  Serial.println(tr);
  Serial.print("BL=");
  Serial.println(bl);
  Serial.print("BR=");
  Serial.println(br);
  Serial.println("=======================");
  

  delay(1000);

}
