#include <Servo.h>
Servo lidservo;
Servo armservo; 
Servo flag;

int armPos = 90;  
int lidPos = 90; 
int flagPos =90;


void setup() {
lidservo.attach(2);
armservo.attach(5);
flag.attach(4);

// Servo Default Starting Position

armservo.write(armPos);
flag.write(flagPos);
lidservo.write(lidPos);
}

void loop() {
  if (readline(Serial.read(), buf, 80) > 0) {
    moveAndPrint(atoi(buf));
  }
}

void moveAndPrint(int cmd) {
    switch (cmd) {
    case 11: //Arm +1
        armPos += 1;
        break;
    case 12: //Arm +5
        armPos += 5;
        break;
    case 21: //Arm -1
        armPos -= 1;
        break;
    case 22: //Arm -5
        armPos -= 5;
        break;
    case 31: //Lid +1
        lidPos += 1;
        break;
    case 32: //Lid +5
        lidPos += 5;
        break;
    case 41: //Lid -1
        lidPos -= 1;
        break;
    case 42: //Lid -5
        lidPos -= 5
        break;
    default:
        delay(1);
        break;
        }
    armservo.write(armPos);
    flag.write(flagPos);
    lidservo.write(lidPos);
 
 }
  
int readline(int readch, char *buffer, int len) {
  static int pos = 0;
  int rpos;

  if (readch > 0) {
    switch (readch) {
    case '\r': // Ignore CR
      break;
    case '\n': // Return on new-line
      rpos = pos;
      pos = 0;  // Reset position index ready for next time
      return rpos;
    default:
      if (pos < len - 1) {
        buffer[pos++] = readch;
        buffer[pos] = 0;
      }
    }
  }
  return 0;
} 
       
    
    

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




















