#include <Servo.h>
Servo lidservo;
Servo armservo; 
Servo flag;

int armPos = 90;  
int lidPos = 90; 
int flagPos = 90;

char buf[80]; //serial buffer

void setup() {
lidservo.attach(3);
armservo.attach(5);
flag.attach(12);

// Servo Default Starting Position

armservo.write(armPos);
flag.write(flagPos);
lidservo.write(lidPos);

Serial.begin(9600);
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
        lidPos -= 5;
        break;
    case 51: //Flag +1
        flagPos += 1;
        break;
    case 52: //flag +5
        flagPos += 5;
        break;
    case 61: //flag -1
        flagPos -= 1;
        break;
    case 62: //flag -5
        flagPos -= 5;
        break;
    default:
        delay(1);
        break;
        }
    armservo.write(armPos);
    flag.write(flagPos);
    lidservo.write(lidPos);
 
    
    Serial.print("ArmPos: ");
    Serial.println(armPos);
    
    Serial.print("LidPos: ");
    Serial.println(lidPos);
    
    Serial.print("FlagPos: ");
    Serial.println(flagPos);
 
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
       



















