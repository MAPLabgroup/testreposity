//sender
// this code creates an arduino which acts as a trigger sender for another one, over serial


void setup() {
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
// uncomment the correct version you want to use: "manual" is the user or computer itself triggers the communication line ad hoc; "automated" simply communicates in a loop (especially useful for debugging)

// ~~~ MANUAL communication
  // Check if data is available on the serial port
  if (Serial.available() > 0) {
    char receivedChar = Serial.read(); // Read the incoming data

    // If the received character is 'J', trigger an action
    if (receivedChar == 'J') {
      digitalWrite(13, HIGH);  // Example: Turn on an LED
      digitalWrite(10, HIGH); // digital signal to receiver arduino
      delay(500);                       // Delay for half a second
      digitalWrite(13, LOW);   // Turn off the LED
      digitalWrite(10, LOW); // digital signal to receiver arduino
      delay(500); //build in delay so this cannot happen sooner than 500ms
// ~~~

// ~~~ AUTOMATED communication version. Loops the light on and off and sends the signal to the receiver on and off
  //Serial.print('H');
  // digitalWrite(10, HIGH);
  // digitalWrite(13, HIGH);
  // delay(1000);
  // //Serial.print('L');
  // digitalWrite(10, LOW);
  // digitalWrite(13, LOW);
  // delay(1000);
// ~~~
    }
  }
}