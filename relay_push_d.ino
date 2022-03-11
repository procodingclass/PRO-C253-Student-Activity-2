

#include <ezButton.h>

#define BUTTON_PIN 22  
#define RELAY_PIN  18  

ezButton button(BUTTON_PIN);  // create ezButton object that attach to pin 7;

int relay_state = LOW;   // the current state of relay

void setup() {
  Serial.begin(9600);         
  pinMode(RELAY_PIN, OUTPUT); 
  button.setDebounceTime(50); 
}

void loop() {
  button.loop(); // MUST call the loop() function first

  if (button.isPressed()) {
    Serial.println("The button is pressed");
   
    relay_state = !relay_state;

    digitalWrite(RELAY_PIN, relay_state);
  }
}
