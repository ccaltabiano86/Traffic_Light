int buttonPin_1   = 5;   // the digital input pin connected to the button 
int buttonPin_2   = 6;   // the digital input pin connected to the button 
int buttonState_1 = 0;   // variable to store the button state
int buttonState_2 = 0;   // variable to store the button state
// the digital output pin connected to the output
int outputRed     = 9;
int outputOrange  = 10;
int outputGreen   = 11;
int greenLED      = 3;
int orangeLED     = 7;
int redLED        = 4;
int boot          = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(buttonPin_2, INPUT_PULLUP);

  pinMode(outputGreen, OUTPUT);
  pinMode(outputOrange, OUTPUT);
  pinMode(outputRed, OUTPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(orangeLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  // Set Orange and Green Relays to OFF
  // digitalWrite(outputRed, HIGH);            // set the output pin to HIGH
  digitalWrite(outputOrange, HIGH);         // set the output pin to HIGH
  digitalWrite(outputGreen, HIGH);          // set the output pin to HIGH

  // Check if first boot, and set Red LED to ON
  if (boot == 0) {
    digitalWrite(redLED, HIGH);
    boot = 1;
  }

  // Set Ornage and Green LEDs to OFF
  digitalWrite(orangeLED, LOW);
  digitalWrite(greenLED, LOW);

  // Red Button
  buttonState_2 = digitalRead(buttonPin_2); // read the value from the button
  if (buttonState_2 == LOW) {               // if the button is pressed
    redButton();
  }

  // Green Button
  buttonState_1 = digitalRead(buttonPin_1); // read the value from the button
  if (buttonState_1 == LOW) {               // if the button is pressed
    greenButton();
  }
}

void redButton() {
  digitalWrite(outputRed, LOW);          // turn the Red OFF
  digitalWrite(redLED, HIGH);
}

void greenButton() {
  digitalWrite(redLED, LOW);
  for (int i = 0; i < 3; i++) {           // loop 3 times
    delay(500);                           // wait for 1 seconds
    digitalWrite(outputRed, HIGH);        // turn the Red OFF
    delay(500);                           // wait for 1 seconds
    digitalWrite(outputRed, LOW);         // turn the Red ON
    digitalWrite(redLED, HIGH);
  }
  for (int i = 0; i < 3; i++) {           // loop 3 times
    digitalWrite(outputOrange, HIGH);     // turn the Orange OFF
    delay(500);                           // wait for 1 seconds
    digitalWrite(outputOrange, LOW);      // turn the Orange ON
    digitalWrite(orangeLED, HIGH);
    delay(500);                           // wait for 1 seconds
  }
  digitalWrite(outputRed, HIGH);          // turn the Red OFF
  digitalWrite(redLED, LOW);
  digitalWrite(outputOrange, HIGH);       // turn the Orange OFF
  digitalWrite(orangeLED, LOW);
  digitalWrite(outputGreen, LOW);         // turn the Green ON
  digitalWrite(greenLED, HIGH);
  delay(4000); 
}