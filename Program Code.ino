int ledPin = 9;         // assign the LED pin number to a variable
int inputPin = 2;       // assign the PIR sensor input pin number to a variable
int pirState = LOW;     // initialize the PIR state as LOW (no motion detected)

void setup() {
  pinMode(ledPin, OUTPUT);    // set the LED pin as an output
  pinMode(inputPin, INPUT);   // set the PIR sensor pin as an input
  Serial.begin(9600);         // initialize serial communication at 9600 baud
  
  attachInterrupt(digitalPinToInterrupt(inputPin), motionDetected, CHANGE); // attach interrupt to detect motion
}

void loop() {
  // nothing to do in the loop function
}

void motionDetected() {
  int val = digitalRead(inputPin); // read the PIR sensor input and store the value in val
  if (val == HIGH) {           // check if motion is detected
    digitalWrite(ledPin, HIGH);  // turn on the LED
    if (pirState == LOW) {       // check if motion was not detected previously
      Serial.println("Motion detected!"); // print message to serial monitor
      pirState = HIGH;          // set the PIR state to HIGH (motion detected)
    }
  } else {
    digitalWrite(ledPin, LOW);   // turn off the LED
    if (pirState == HIGH) {       // check if motion was detected previously
      Serial.println("Motion ended!");  // print message to serial monitor
      pirState = LOW;           // set the PIR state to LOW (no motion detected)
    }
  }
}
