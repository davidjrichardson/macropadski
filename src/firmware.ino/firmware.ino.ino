#include <Keyboard.h>

#include <Bounce2.h>

/**
 * Row and column pins are the rows and columns for the keys in the keypad. The index
 * of the pin in the array is its physical position e.g.: rowPins[0] is the pin for the
 * first row of keys.
 */
int rowPins[] = {2, 3};
int colPins[] = {7, 8, 16, 17, 18};

Bounce keys[2][5];

// Debug flag for building the firmware in debug mode
bool DEBUG = true;

void setup() {
  // Set up the row pins for output (acting as ground plane for the input)
  for (int i = 0; i < 2; i++) {
    pinMode(rowPins[i], OUTPUT);
    // The default state for each row is HIGH since the pullup resistor will 
    // make the input HIGH (and we detect keypress on LOW signal)
    digitalWrite(rowPins[i], HIGH);
  }

  // Set up the column pins (float HIGH until connected to ground)
  for (int i = 0; i < 5; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }

  // If the firmware is built in debug mode then
  if (DEBUG) {
    pinMode(LED_BUILTIN, OUTPUT);
  
    Serial.begin(9600);
    while (!Serial) {;}
    Serial.println("Debug mode enabled");
  }

  for (int i = 0; i < 2; i++) {
    for (int k = 0; k < 5; k++) {
      Bounce b = Bounce();
      b.attach(colPins[k]);
      b.interval(1);

      keys[i][k] = b;
    }
  }
}

void loop() {
  for (int i = 0; i < 2; i++) {
    // Set the row we're checking to LOW since the pullup resistor will do the work here
    int rowPin = rowPins[i];
    int altRowPin = (rowPin == 2 ? 3 : 2);
    digitalWrite(rowPin, LOW);
    digitalWrite(altRowPinn, HIGH);

    // Iterate over the columns
    for (int k = 0; k < 5; k++) {
      Bounce key = keys[i][k];
      key.update();
      
      if (DEBUG) {
        Serial.print("Key value on row ");
        Serial.print(i+1);
        Serial.print(" col ");
        Serial.print(k+1);
        Serial.print(": ");
        Serial.println(key.read());
      }

      if (key.fell()) {
        digitalWrite(LED_BUILTIN, HIGH);
      } else {
        digitalWrite(LED_BUILTIN, LOW);
      }
      delay(50);
    }
    // Reset the row logic state
    digitalWrite(rowPin, HIGH);
    delay(50);
  }
}
