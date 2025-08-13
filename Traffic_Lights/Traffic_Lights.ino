int buttonPin_1   = 5;   // the digital input pin connected to the button 
int buttonPin_2   = 6;   // the digital input pin connected to the button 
int buttonState_1 = 0;   // variable to store the button state
int buttonState_2 = 0;   // variable to store the button state
// the digital output pin connected to the output
int outputRed     = 9;
int outputOrange  = 10;
int outputGreen   = 11;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  

  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(buttonPin_2, INPUT_PULLUP);
  pinMode(outputGreen, OUTPUT);
  pinMode(outputOrange, OUTPUT);
  pinMode(outputRed, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

  // digitalWrite(outputRed, HIGH);            // set the output pin to HIGH
  digitalWrite(outputOrange, HIGH);         // set the output pin to HIGH
  digitalWrite(outputGreen, HIGH);          // set the output pin to HIGH

  buttonState_2 = digitalRead(buttonPin_2); // read the value from the button
  if (buttonState_2 == LOW) {               // if the button is pressed
    digitalWrite(outputRed, LOW);          // turn the Red OFF
  }


  buttonState_1 = digitalRead(buttonPin_1); // read the value from the button
  if (buttonState_1 == LOW) {               // if the button is pressed
    for (int i = 0; i < 3; i++) {           // loop 3 times
      digitalWrite(outputRed, HIGH);        // turn the Red OFF
      delay(500);                           // wait for 1 seconds
      digitalWrite(outputRed, LOW);         // turn the Red ON
      delay(500);                           // wait for 1 seconds
    }
    for (int i = 0; i < 3; i++) {           // loop 3 times
      digitalWrite(outputOrange, HIGH);     // turn the Orange OFF
      delay(500);                           // wait for 1 seconds
      digitalWrite(outputOrange, LOW);      // turn the Orange ON
      delay(500);                           // wait for 1 seconds
    }
    digitalWrite(outputRed, HIGH);          // turn the Red OFF
    digitalWrite(outputOrange, HIGH);       // turn the Orange OFF
    digitalWrite(outputGreen, LOW);         // turn the Green ON
    delay(4000); 
  }
}