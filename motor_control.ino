// Motor Driver Pins
const int IN1_PIN = 2; // Example PWM pin
const int IN2_PIN = 3; // Example PWM pin
const int Sleep = 4;
//const int Fan = 5;


// PWM Duty Cycle
int pwmSpeed = 50; // Range from 0 to 255
int FanSpeed = 200;

void setup() {
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  pinMode(Sleep, OUTPUT);

  // Initialize motor to brake low state
  digitalWrite(IN1_PIN, LOW);
  digitalWrite(IN2_PIN, LOW);
}

void loop() {
  


analogWrite(IN1_PIN, pwmSpeed);
analogWrite(IN2_PIN, 0);
digitalWrite(Sleep, HIGH);
Serial.print("This works");
//analogWrite(Fan, FanSpeed);
//delay(3000);


//motorReverse();
//delay(3000);
//
}

void motorReverse() {
  analogWrite(IN1_PIN, 0);
  analogWrite(IN2_PIN, pwmSpeed);
  digitalWrite(Sleep, HIGH);
}
//
//void motorBrakeHigh() {
//  analogWrite(IN1_PIN, 255); // Assuming 255 is the maximum PWM value
//  analogWrite(IN2_PIN, 255); // Assuming 255 is the maximum PWM value
//}
//
//// Example function to get the operating mode (you need to implement this)
//int getOperatingMode() {
//  return FORWARD; 
//}
