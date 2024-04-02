// Remote Control
#define CH1 3
#define CH2 29
#define CH3 13
#define CH4 15
#define CH5 25
#define CH6 6

int ch1Value;
int ch2Value;
int ch3Value;
int ch4Value; 
int ch5Value;
int ch6Value;


const int Fan = 10;

// Motors
// Motor A
const int motorAPin1 = 6; //PWM
const int motorAPin2 = 8; //PWM
const int sleepA = 9;

// Motor B
const int motorBPin1 = 4; //PWM
const int motorBPin2 = 2; //PWM
const int sleepB = 11;

int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

//void moveRobot(int motorAPower, int motorBPower) {
//  // Move Motor A
//  if (motorAPower > 0) {
//    digitalWrite(motorAPin1, HIGH);
//    digitalWrite(motorAPin2, LOW);
//    analogWrite(sleepA, motorAPower);
//  } else if (motorAPower < 0) {
//    digitalWrite(motorAPin1, LOW);
//    digitalWrite(motorAPin2, HIGH);
//    analogWrite(sleepA, -motorAPower);
//  } else {
//    analogWrite(sleepA, 0);
//  }
//  
//  // Move Motor B
//  if (motorBPower > 0) {
//    digitalWrite(motorBPin1, HIGH);
//    digitalWrite(motorBPin2, LOW);
//    
//  } else if (motorBPower < 0) {
//    digitalWrite(motorBPin1, LOW);
//    digitalWrite(motorBPin2, HIGH);
//    analogWrite(sleepB, -motorBPower);
//  } else {
//    analogWrite(sleepB, 0);
//  }
//}

void setup() {
  Serial.begin(115200);
  
  // Set all pins as outputs for motors
  pinMode(motorAPin1, OUTPUT);
  pinMode(motorAPin2, OUTPUT);
  
  pinMode(motorBPin1, OUTPUT);
  pinMode(motorBPin2, OUTPUT);
  digitalWrite(sleepA, HIGH);
  digitalWrite(sleepB, HIGH);
}

void loop() {
  // Get values for each channel
  ch1Value = readChannel(CH1, -255, 255, 255); // Left joystick left/right
  ch2Value = readChannel(CH2, -255, 255, 0); // Right joystick up/down
  ch3Value = readChannel(CH3, 0, 100, 0); // Left joystick up/down
  ch4Value = readChannel(CH4, -255, 255, 0); // Left joystick left/right
  ch5Value = readChannel(CH5, 0, 255, 0);

  analogWrite(Fan, abs(ch5Value));
  
  

                      
  // Print joystick values to Serial Monitor
  Serial.print("Ch1: ");
  Serial.print(ch1Value);
  Serial.print(" | Ch2: ");
  Serial.print(ch2Value);
  Serial.print(" | Ch3: ");
  Serial.print(ch3Value);
  Serial.print(" | Ch4: ");
  Serial.print(ch4Value);
  Serial.print(" | Ch5: ");
  Serial.print(ch5Value);
  Serial.println();
  
if (abs(ch2Value) < 10) {

  if (ch4Value > 0) {
  analogWrite(motorAPin1, abs(ch4Value+4));
  analogWrite(motorAPin2, 0);
  analogWrite(motorBPin1, 0);
  analogWrite(motorBPin2, abs(ch4Value+4));
  
}

else if (ch4Value < 0) {
  analogWrite(motorAPin1, 0);
  analogWrite(motorAPin2, abs(ch4Value+4));
  analogWrite(motorBPin1, abs(ch4Value+4));
  analogWrite(motorBPin2, 0);
  }
}

else {
  if (ch2Value > 0){
    analogWrite(motorAPin1, 0);
    analogWrite(motorAPin2, abs(ch2Value+4));
    analogWrite(motorBPin1, 0);
    analogWrite(motorBPin2, abs(ch2Value+4));
    
    }
   else if (ch2Value < 0) {
  analogWrite(motorAPin1, abs(ch2Value+4));
  analogWrite(motorAPin2, 0);
  analogWrite(motorBPin1, abs(ch2Value+4));
  analogWrite(motorBPin2, 0);
   }
}
  delay(100);
}
