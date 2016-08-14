//source code to control dc and servo motors using Arduino

#ifndef DUALCONTROLLER_H
#define DUALCONTROLLER_H

#include <Arduino.h>
#include <Servo.h>

enum DcMotorState {In, Out };

class DcMotorController
{
  public:
    // Initialises the DcMotor
    DcMotorController(int cp1, int cp2, int ep, DcMotorState is, int as, int dt)
    {
      controlPin[0] = cp1; 
      controlPin[1] = cp2;
      enablePin = ep;
      state = is;
      analogSpeed = as;
      delayTime = dt;
    }

    // Toggles the state from in to out or out to in when called.
    void ToggleState()
    {
      if (state == In) {
        digitalWrite(controlPin[0], HIGH);
        digitalWrite(controlPin[1], LOW);

      } else {
        digitalWrite(controlPin[0], LOW);
        digitalWrite(controlPin[1], HIGH);
      }

      analogWrite(enablePin, analogSpeed);
      delay(delayTime);

      //brake
      digitalWrite(controlPin[0], LOW);
      digitalWrite(controlPin[1], LOW);
      
      ChangeState();
    }

    DcMotorState GetState()
    {
      return state;
    }
  private:
    // helper function that changes local state variable
    void ChangeState()
    {
      if (state == In)
        state = Out;
      else
        state = In;
    }

    DcMotorState state;  // holds the current state of the DC Motor

     // Pin variables
     int controlPin[2];
     int enablePin;

     int analogSpeed;
     int delayTime;
};

class ServoController : public Servo
{
  public:
    ServoController()
    {
      state = 0;

      delayTime = 10;
    }

    void attach(int pin)
    {
      Servo::attach(pin);
      write(state);
    }

    
    void RotateServo(int target)
    {
      int increment;
      digitalWrite(13, HIGH);
      
      if (target > state)
        increment = 1;
      else
        increment = -1;

      while (state != target) {
        write(state + increment);
        state += increment;

        delay(delayTime);
      }
      
      digitalWrite(13, LOW);
    }

    int GetState()
    {
      return state;
    }
    
  private:
    // delay between moving 1 degree increments
    int delayTime;

    // Current state of the motor.
    int state;
};

#endif

