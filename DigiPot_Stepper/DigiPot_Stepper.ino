#include <AccelStepper.h>

#define potpin    0
#define dirPin    5
#define stepPin   4
#define enPin     6
#define motorInterfaceType 1

AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

int val = 0;

void setup() {
  stepper.setMaxSpeed(100);
  stepper.setAcceleration(200);
  stepper.setEnablePin(enPin);
  stepper.setPinsInverted(false, false, true);

  Serial.begin(9600);
}

void loop() {

  val = 0;
  
  for (int i = 0; i < 30; i++) {
    val = val + analogRead(potpin); // reads the value of the potentiometer (value between 0 and 1023)
    delay(5);
  }
  val = val / 30;

  Serial.println(val);

  val = map(val, 0, 1023, 0, 80);

  if(val == stepper.currentPosition()) {
    stepper.disableOutputs();
  }
  else {
    stepper.enableOutputs();
    
    stepper.moveTo(val);
  
    stepper.run();
    while(stepper.isRunning()) {
      stepper.run();
      delay(1);
    }
  }
  

  
}
