#include <Servo.h>

#define potpin 0  // analog pin used to connect the control potentiometer
#define readpin 1  // analog pin used to connect the driven potentiometer

Servo myservo;  // create servo object to control a servo

int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(4);  // attaches the servo on pin 9 to the servo object
  
  Serial.begin(9600);

  pinMode(potpin, INPUT);
  pinMode(readpin, INPUT);
}

void loop() {
  
  val = 0;
  
  for (int i = 0; i < 10; i++)
  {
    val = val + analogRead(potpin); // reads the value of the potentiometer (value between 0 and 1023)
    delay(2);
  }
  
  val = val / 10;
  
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(20);                           // waits for the servo to get there

  Serial.println(analogRead(readpin));
}


