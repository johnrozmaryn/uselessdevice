#include <Servo.h>
Servo lidservo;
Servo armservo; 
Servo flag;

int armOff = 160;  //This is the arm value where the switch is turmed off
int armFake = 140; //This is the arm value that may be touching the switch, but not turning it off 
int armIn = 35;    //This is the arm value where the arm is inside the box / neutral

int lidClose = 90;  //This is the lid value where the lid is closed
int lidNarrow = 50;   //This is the lid value where the lid is opened part way
int lidOpen = 20;   //This is the lid value where the lid is opened all the way

int flagOff = 50;  //This is when the surrender flag is fully down
int flagStart = 125;   //This is when the surrender flag starts to wave
int flagEnd = 175;    //This is when the surrender flag ends the wave

int armpin = 7;
int lidpin = 8;

int action = 1;
//int pos = 0;  //This is from the original code. I don't think it needs to be here.

void setup() {
pinMode(armpin,INPUT);
pinMode(lidpin,INPUT);
lidservo.attach(2);
armservo.attach(5);
flag.attach(4);

// Servo Default Starting Position

armservo.write(armIn);
flag.write(flagOff);
lidservo.write(lidClose);
}

void loop() {

// Action Selection starting with 1


  if (digitalRead(armpin) == HIGH)
	armservo.write(armOff);
  else
	armservo.write(armIn);
 

  if (digitalRead(lidpin) == HIGH)
	lidservo.write(lidOpen);
  else 
	lidservo.write(lidClose);


delay(100);

}




















