#include <Servo.h>
Servo lidservo;
Servo armservo; 
Servo flag;

int armOff = 160;  //This is the arm value where the switch is turmed off
int armFake = 120; //This is the arm value that may be touching the switch, but not turning it off 
int armIn = 20;    //This is the arm value where the arm is inside the box / neutral

int lidClose = 130;  //This is the lid value where the lid is closed
int lidNarrow = 50;   //This is the lid value where the lid is opened part way
int lidOpen = 60;  //This is the lid value where the lid is opened all the way

int flagOff = 50;  //This is when the surrender flag is fully down
int flagStart = 125;   //This is when the surrender flag starts to wave
int flagEnd = 175;    //This is when the surrender flag ends the wave

int switchpin = 7;

void setup() {
    pinMode(switchpin,INPUT_PULLUP);
    lidservo.attach(3);
    armservo.attach(5);

// Servo Default Starting Position

    armservo.write(armIn);
    flag.write(flagOff);
    lidservo.write(lidClose);
}

void loop() {

  if (digitalRead(switchpin) == LOW) {
    lidservo.write(lidOpen);
    delay(1000);
    armservo.write(armOff);
    delay(500); 
    armservo.write(armIn);
    delay(1000);
    lidservo.write(lidClose);
    delay(1000);
	}

delay(1000);

}




















