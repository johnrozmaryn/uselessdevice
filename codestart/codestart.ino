#include <Servo.h>
Servo lidservo;
Servo armservo; 
Servo flag;

int armOff = 160;  //This is the arm value where the switch is turmed off
int armFake = 130; //This is the arm value that may be touching the switch, but not turning it off 
int armIn = 20;    //This is the arm value where the arm is inside the box / neutral

int lidClose = 130;  //This is the lid value where the lid is closed
int lidNarrow = 60;   //This is the lid value where the lid is opened part way
int lidOpen = 60;   //This is the lid value where the lid is opened all the way

int flagOff = 50;  //This is when the surrender flag is fully down
int flagStart = 125;   //This is when the surrender flag starts to wave
int flagEnd = 175;    //This is when the surrender flag ends the wave

int switchpin = 7;
int action = 1;
//int pos = 0;  //This is from the original code. I don't think it needs to be here.

void setup() {
pinMode(switchpin,INPUT_PULLUP);
lidservo.attach(3);
armservo.attach(5);
//flag.attach(4);

// Servo Default Starting Position

armservo.write(armIn);
//flag.write(flagOff);
lidservo.write(lidClose);
}

void loop() {

// Action Selection starting with 1

  if (digitalRead(switchpin) == LOW)
  {
  if (action > 8) {
    action = 1;
  }  
    if (action == 1) {
    action1();
    }
    else if (action == 2) {
    action2();
    }
    else if (action == 3) {
    action3();
    }
    else if (action == 4) {
    action4();
    }
    else if (action == 5) {
    action5();
    }
    else if (action == 6) {
    action6();
    }
    else if (action == 7) {
    action7();
    }
    else if (action == 8) {
    action7();
    }

    action += 1;
    
  }
}

//The Following are actions that are chosen chronologically

void action1() {
  lidservo.write(lidOpen);
  delay(1000);
  armservo.write(armOff);
  delay(500); 
  armservo.write(armIn);
  delay(1000);
  lidservo.write(lidClose);
  delay(1000);
}

void action2() {
  lidservo.write(lidNarrow);
  delay(100);
  armservo.write(armOff);
  delay(500);
  armservo.write(armIn);
  delay(100);
  lidservo.write(lidClose);
}

void action3() {
  sweep(lidservo,lidClose,lidOpen,1,50);
  armservo.write(armOff);
  delay(250);
  armservo.write(armIn);
  delay(100);
  lidservo.write(lidClose);
}

void action4() {
  delay(250);
  lidservo.write(lidNarrow);
  delay(100);
  armservo.write(armOff);
  delay(2500);
  sweep(armservo,armOff,armIn,1,50);
  lidservo.write(lidClose);
  armservo.write(armIn);
}

void action5() {
  lidservo.write(lidNarrow);
  delay(500);
  lidservo.write(lidClose);
  delay(500);
  lidservo.write(lidNarrow);
  delay(500);
  lidservo.write(lidClose);
  delay(500);
  lidservo.write(lidNarrow);
  delay(500);
  lidservo.write(lidClose);
  delay(2500);
  lidservo.write(lidNarrow);
  delay(100);
  armservo.write(armOff);
  delay(500);
  armservo.write(armIn);
  delay(100);
  lidservo.write(lidClose);
}

void action6() {
  lidservo.write(lidNarrow);
  delay(100);
  armservo.write(armFake);
  delay(250);
  armservo.write(armIn);
  delay(100);
  lidservo.write(lidClose);
  delay(250);
  lidservo.write(lidNarrow);
  delay(100);
  armservo.write(armFake);
  delay(250);
  armservo.write(armIn);
  delay(100);
  lidservo.write(lidClose);
  delay(250);
  lidservo.write(lidNarrow);
  delay(100);
  armservo.write(armFake);
  delay(250);
  armservo.write(armIn);
  delay(100);
  lidservo.write(lidClose);
  delay(250);  
  lidservo.write(lidNarrow);
  delay(100);
  armservo.write(armOff);
  delay(500);
  armservo.write(armIn);
  delay(100);
  lidservo.write(lidClose);
}

void action7() {
  sweep(lidservo,lidClose,lidOpen,2,50);
  sweep(armservo,armIn,armFake,2,100);
  armservo.write(armOff);
  delay(500);
  sweep(armservo,armOff,armIn,2,50);
  sweep(lidservo,lidOpen,lidClose,2,50);
  lidservo.write(lidClose);
}

void action8() {
/*I removed a possibly duplicate check of the switch position here. If I bonk out, check on putting it back in */	
  delay(1000);
	sweep(lidservo,lidClose,lidOpen,2,50);
	sweep(flag,flagOff,flagEnd,10,50);
	delay(250);

	sweep(flag,flagEnd,flagStart,10,50);
	sweep(flag,flagStart,flagEnd,10,50);
	sweep(flag,flagEnd,flagStart,10,50);
	sweep(flag,flagStart,flagEnd,10,50);
	sweep(flag,flagEnd,flagStart,10,50);
	sweep(flag,flagStart,flagEnd,10,50);
	sweep(flag,flagEnd,flagStart,10,50);
	sweep(flag,flagStart,flagEnd,10,50);
	sweep(flag,flagEnd,flagStart,10,50);
	sweep(flag,flagStart,flagEnd,10,50);
	delay(250);
	sweep(flag,flagEnd,flagOff,10,50);

	sweep(lidservo,lidOpen,lidClose,2,50);
	delay(2000);
    lidservo.write(lidNarrow);
	delay(100);
	armservo.write(armOff);
	delay(250);
	armservo.write(armIn);
	delay(100);
	lidservo.write(lidClose);
}

void sweep(Servo myservo, int startpos, int endpos, int increment, int dTime){
    int pos;
	if (startpos < endpos) {
		for(pos = startpos; pos < endpos; pos += increment)
		{
			myservo.write(pos);
			delay(dTime);
		}
	}
	else {
		for(pos = startpos; pos > endpos; pos -= increment)
		{
			myservo.write(pos);
			delay(dTime);
		}
	}
}
