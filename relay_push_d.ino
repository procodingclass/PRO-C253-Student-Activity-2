/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-button-toggle-relay
 */

#include <ezButton.h>

#define BUTTON_PIN 22  // ESP32 pin GIOP22 connected to button's pin
#define RELAY_PIN  18  // ESP32 pin GIOP27 connected to relay's pin

ezButton button(BUTTON_PIN);  // create ezButton object that attach to pin 7;

// The below are variables, which can be changed
int relay_state = LOW;   // the current state of relay

void setup() {
  Serial.begin(9600);         // initialize serial
  pinMode(RELAY_PIN, OUTPUT); // set ESP32 pin to output mode
  button.setDebounceTime(50); // set debounce time to 50 milliseconds
}

void loop() {
  button.loop(); // MUST call the loop() function first

  if (button.isPressed()) {
    Serial.println("The button is pressed");

    // toggle state of relay
    relay_state = !relay_state;

    // control relay arccoding to the toggled state
    digitalWrite(RELAY_PIN, relay_state);
  }
}
