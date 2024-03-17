/*
  Arduino FS-I6X Demo
  fsi6x-arduino-uno.ino
  Read output ports from FS-IA6B receiver module
  Display values on Serial Monitor
  
  Channel functions by Ricardo Paiva - https://gist.github.com/werneckpaiva/
  
  DroneBot Workshop 2021
  https://dronebotworkshop.com
*/

// Define Input Connections
#define CH1 3
#define CH2 5
#define CH3 6
#define CH4 9
#define CH5 7
#define CH6 6

// Integers to represent values from sticks and pots
int ch1Value;
int ch2Value;
int ch3Value;
int ch4Value; 
int ch5Value;
int Fan = 5;
int IN1_PIN = 2;
int IN2_PIN = 3;
int motor_on = 50 ;
int Sleep = 4;
// Boolean to represent switch value
int ch6Value;

// Read the number of a specified channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

// Read the switch channel and return a boolean value
bool readSwitch(byte channelInput, bool defaultValue){
  int intDefaultValue = (defaultValue)? 100: 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}

void setup(){
  // Set up serial monitor
  Serial.begin(115200);
  digitalWrite(Sleep, HIGH);
  // Set all pins as inputs
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
  pinMode(CH3, INPUT);
  pinMode(CH4, INPUT);
  pinMode(CH5, INPUT);
  pinMode(CH6, INPUT);
}


void loop() {
  
  // Get values for each channel
  ch1Value = readChannel(CH1, -100, 100, 0);
  ch2Value = readChannel(CH2, -100, 100, 0);
  ch3Value = readChannel(CH3, -100, 100, -100);
  ch4Value = readChannel(CH4, -100, 100, 0);
  ch5Value = readChannel(CH5, -100, 100, 0);
  ch6Value = readChannel(CH6, -50,50,0);
  ch5Value = ch5Value + 101 ;
  ch5Value = round((ch5Value * (2.55/2))) ;
  analogWrite(Fan, ch5Value);

  analogWrite(IN1_PIN, ch6Value);
  analogWrite(IN2_PIN, 0);
  
  
  // Print to Serial Monitor
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
  Serial.print(" | Ch6: ");
  Serial.println(ch6Value);
  
  delay(500);
}
