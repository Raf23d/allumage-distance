//1s:35cm
//2s:70cm
//3s:105cm

//45°:0289ms
//90°:0577ms
//180°:1155ms

#include <AFMotor.h>




AF_DCMotor MotorD(1);
AF_DCMotor MotorG(2);
int VRx = A0;
int VRy = A1;
int xPosition = 0;
int yPosition = 0;
int mapX = 0;
int mapY = 0;
const unsigned long MOTORS_INTERVAL = 200;
unsigned long previousMillis = 0;
byte etatAction = 0;

unsigned long nbAlea;
unsigned long previousMillis2 = 0;

unsigned long previousMillis3 = 0;

byte etatMoteurs = 1;
unsigned long previousMillis4 = 0;


void setup(){
  MotorG.setSpeed(228);
  MotorD.setSpeed(241);
  
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);

  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  delay(300);
  digitalWrite(2, LOW);
}



void loop(){
   unsigned long currentMillis = millis();                     //temps

   
   //bruit (wouaf wouaf)
   if(currentMillis - previousMillis2 >= 20000){
   digitalWrite(2, HIGH);
   previousMillis2 = currentMillis; }
   if(currentMillis - previousMillis2 >= 300) {
   digitalWrite(2, LOW);
   }
  
  
  
  //direction avec le joystick
  if(currentMillis - previousMillis < MOTORS_INTERVAL) {
    etatAction = 0;
  }
  
  if(currentMillis - previousMillis >= MOTORS_INTERVAL) {
  previousMillis = currentMillis;
  
  yPosition = analogRead(VRy);                               //mesure joystick
  xPosition = analogRead(VRx);
  mapY = map(yPosition, 0, 1023, 512, -512);
  mapX = map(xPosition, 0, 1023, -512, 512);
  
  Serial.print("  Y: ");
  Serial.print(mapY);
  Serial.print(" | X: ");
  Serial.print(mapX);

 MotorG.run(RELEASE);                                        //arret des moteurs
 MotorD.run(RELEASE);
 etatMoteurs = 1;
 
  
  if (mapX < -3)                             //en avant
{
   MotorG.run(FORWARD);
   MotorD.run(FORWARD);
   etatMoteurs = 0;
}
/*  if (mapX < -3)    //en arriere
{
  
} */
  if (mapY < -3)                            //à droite
{
   MotorG.run(FORWARD);
   MotorD.run(RELEASE);
   etatMoteurs = 0;
}
  if (mapY > -1)                            //à gauche
{
   MotorG.run(RELEASE);
   MotorD.run(FORWARD);
   etatMoteurs = 0;
}
 }

 if (etatMoteurs == 1) {
  digitalWrite(2, HIGH);
  previousMillis2 = currentMillis; }
  if(currentMillis - previousMillis2 >= 300) {
  digitalWrite(2, LOW);
  }
  
 
}

