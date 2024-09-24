// Define LED and switch connections
const int greenLedPin = 12;   // Green LED connected to digital pin 12
const byte redLedPin = 13;    // Red LED connected to digital pin 13
const int button1Pin = 4;     // Button 1 connected to digital pin 4
const int button2Pin = 3;     // Button 2 connected to digital pin 3
const byte buttonPin = 2;     // Button R connected to digital pin 2 (interupt)


int button1State = 0;
int button2State = 0;

// Variables for timing
unsigned long startTime = 0;             // Time when the green LED is turned on
unsigned long interval  = 1;             // Time when the green LED is turned off
const unsigned long interval1 = 180000;  // 3 minutes in milliseconds (180000)
const unsigned long interval2 = 150000;  // 2.5 minutes in milliseconds (150000)


void checkSwitch() {
  // Check status of switch
  // Toggle LED if button pressed

  if (digitalRead(buttonPin) == LOW) {
    // Indicate state on LED
    digitalWrite(redLedPin, LOW);        // Relay LOW = ON
    digitalWrite(greenLedPin, HIGH);     // Relay HIGH = OFF
  }
}

void setup() {
  // Set LED pin as output
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  // Set switch pin as INPUT with pullup
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);

  // Attach Interrupt to Interrupt Service Routine
  attachInterrupt(digitalPinToInterrupt(buttonPin),checkSwitch, FALLING); 
}

void loop() {
  
  // Read the state of button 1
  button1State = digitalRead(button1Pin);
  if (button1State == LOW) {
    // Button 1 is pressed, turn on the green LED and start the timer
    digitalWrite(greenLedPin, LOW);      // Relay LOW = ON
    digitalWrite(redLedPin, HIGH);       // Relay HIGH = OFF
    interval = interval1;
    startTime = millis();
  }
  
  // Read the state of button 2
  button2State = digitalRead(button2Pin);
    if (button2State == LOW) {
    // Button 2 is pressed, turn on the green LED and start the timer
    digitalWrite(greenLedPin, LOW);      // Relay LOW = ON
    digitalWrite(redLedPin, HIGH);       // Relay HIGH = OFF
    interval = interval2;
    startTime = millis();
  }

  // Check if the timer has elapsed
  if (millis() - startTime >= interval) {
    digitalWrite(greenLedPin, HIGH);     // Turn off the green LED
    digitalWrite(redLedPin, LOW);        // Turn on the red LED
  }
}