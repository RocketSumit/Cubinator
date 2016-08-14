//source code to control the movement of robotic hand

#ifndef ARMMOVEMENT_H
#define ARMMOVEMENT_H

#include <Arduino.h>
#include "DualController.h"
#include <Servo.h>

//servo and dc motor functions decalarations
DcMotorController dcF(11,10,9, In, 255, 300), dcB(4,5,6,In, 255,300), dcL(7,8,1, In, 255, 300),dcR(2,3,4,In,255,300);

ServoController servoF, servoB, servoL, servoR;

//rotatation of face by 90 degree clockwise
void Clock(DcMotorController dcF, ServoController servoF)
{
  servoF.RotateServo(90);
  delay(500);
  dcF.ToggleState();
  delay(500);
  servoF.RotateServo(0);
  delay(500);
  dcF.ToggleState();
  delay(500);
}

//rotatation of face by 90 degree counterclockwise
void AntiClock(DcMotorController dcF, ServoController servoF)
{
  dcF.ToggleState();
  delay(500);
  servoF.RotateServo(90);
  delay(500);
  dcF.ToggleState();
  delay(500);
  servoF.RotateServo(0);
  delay(500);
}

//rotatation of face by 180 degree
void DoubleTurn(DcMotorController dcF, ServoController servoF)
{
  for(int i = 0; i < 2; i++)
    Clock(dcF, servoF);
}

void Rotate(char* face){
  
  if(strcmp(face, "F") == 0)
    Clock(dcF, servoF);
  
  else if(strcmp(face, "F'") == 0)
    AntiClock(dcF, servoF);
  
  else if(strcmp(face, "F2") == 0)
    DoubleTurn(dcF, servoF);

  if(strcmp(face, "B") == 0)
    Clock(dcB, servoB);
  
  else if(strcmp(face, "B'") == 0)
    AntiClock(dcB, servoB);
  
  else if(strcmp(face, "B2") == 0)
    DoubleTurn(dcB, servoB);

  if(strcmp(face, "L") == 0)
    Clock(dcL, servoL);
  
  else if(strcmp(face, "L'") == 0)
    AntiClock(dcL, servoL);
  
  else if(strcmp(face, "L2") == 0)
    DoubleTurn(dcL, servoL);  

  if(strcmp(face, "R") == 0)
    Clock(dcR, servoR);
  
  else if(strcmp(face, "R'") == 0)
    AntiClock(dcR, servoR);
  
  else if(strcmp(face, "R2") == 0)
    DoubleTurn(dcR, servoR);
}

#endif

