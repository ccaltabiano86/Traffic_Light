// Define pin numbers for buttons and LEDs
const int greenLedPin = 12;  // Green LED connected to digital pin 13
const int redLedPin = 13;    // Red LED connected to digital pin 12
const int button1Pin = 4;    // Button 1 connected to digital pin 2
const int button2Pin = 3;    // Button 2 connected to digital pin 3

// Variables to store button states
int button1State = 0;
int button2State = 0;

// Variables for timing
unsigned long startTime = 0;  // Time when the green LED is turned on
const unsigned long interval = 6000;  // 3 minutes in milliseconds (180000)

void setup() {
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(button1Pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button2Pin), toggleRedLed, FALLING);
}

void loop() {
  // Read the state of button 1
  button1State = digitalRead(button1Pin);

  if (button1State == LOW) {
    // Button 1 is pressed, turn on the green LED and start the timer
    digitalWrite(greenLedPin, HIGH);
    startTime = millis();
    digitalWrite(redLedPin, LOW);
  }

  // Check if the timer has elapsed
  if (millis() - startTime >= interval) {
    digitalWrite(greenLedPin, LOW);  // Turn off the green LED
    // digitalWrite(redLedPin, HIGH);    // Turn on the red LED
    // You can add additional code or actions here if needed
  }
}

void toggleRedLed() {
  // This function is called when button 2 is pressed (interrupt)
  if (digitalRead(button2Pin) == LOW) {
    // Switch was pressed
    digitalWrite(greenLedPin, LOW);  // Turn off the green LED
    digitalWrite(redLedPin, HIGH);  // Turn on the red LED
  }
}