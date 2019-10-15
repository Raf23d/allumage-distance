//1s:35cm
//2s:70cm
//3s:105cm

//45°:0289ms
//90°:0577ms
//180°:1155ms


#include <AFMotor.h>

AF_DCMotor MotorD(1);
AF_DCMotor MotorG(2);

void setup()
{

MotorG.setSpeed(140);
MotorD.setSpeed(148);

}

void loop()
{

   delay(3000);
    MotorG.run(FORWARD); // En avant
    MotorD.run(RELEASE);
   delay(1155);
    MotorG.run(RELEASE); // Arret
    MotorD.run(RELEASE);
   delay(5000);

}
