#include <Bounce2.h>
#include <Keyboard.h>

#define DEBUG false

/**************************
 ******** PIN DEFS ********
 **************************/
int colPin1 = 7;
int colPin2 = 8;
int colPin3 = 16;
int colPin4 = 17;
int colPin5 = 18;

int colPins[] = {colPin1, colPin2, colPin3, colPin4, colPin5};

int row1Pin = 2;
int row2Pin = 3;

int rowPins[] = {row1Pin, row2Pin};


/***************************
 ***** KEY MATRIX DEFS *****
 ***************************/
Bounce key1 = Bounce();
Bounce key2 = Bounce();
Bounce key3 = Bounce();
Bounce key4 = Bounce();
Bounce key5 = Bounce();
Bounce key6 = Bounce();
Bounce key7 = Bounce();
Bounce key8 = Bounce();
Bounce key9 = Bounce();
Bounce key10 = Bounce();

// Use a 2D array for nice code re-use
Bounce *keys[2][5] = {
  {&key1, &key2, &key3, &key4,  &key5}, // Row 1
  {&key6, &key7, &key8, &key9, &key10}  // Row 2
};


/*************************
 ***** KEY CODE DEFS *****
 *************************/
char ctrlKey = 128|131;
char keyCodes[2][5] = {
  {240, 241, 242, 243, 244}, // Row 1
  {245, 246, 247, 248, 249}  // Row 2
};


void setup() {
  // Set the row pins to high outputs
  pinMode(row1Pin, OUTPUT);
  digitalWrite(row1Pin, HIGH);
  pinMode(row2Pin, OUTPUT);
  digitalWrite(row2Pin, HIGH);

  // Set the column pins to inputs with pull-up resistors
  for (int i = 0; i < 5; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }

  // Set up the keys
  for (int i = 0; i < 2; i++) {
    for (int k = 0; k < 5; k++) {
      Bounce *key = keys[i][k];
      key->attach(colPins[k]);
      key->interval(1);
    }
  }

  // Debug output
  if (DEBUG) {
    Serial.begin(9600);
    while (!Serial) {;}
  }

  Keyboard.begin();

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 2; i++) {
    // Set the rows to the correct logic levels
    int lowRow = rowPins[i];
    int highRow = rowPins[(i + 1) % 2];
    digitalWrite(lowRow, LOW);
    digitalWrite(highRow, HIGH);
    
    for (int k = 0; k < 5; k++) {
      // Read the key switches
      Bounce *key = keys[i][k];
      key->update();

      if (key->fell()) {
        Serial.printf("Key code: 0x%x\n", keyCodes[i][k]);
//
//        Keyboard.press(ctrlKey);
        Keyboard.press(keyCodes[i][k]);
        Keyboard.releaseAll();

        if (DEBUG) {
          digitalWrite(LED_BUILTIN, HIGH);
          delay(100);
          digitalWrite(LED_BUILTIN, LOW);
        }
      }
    }
      
    digitalWrite(lowRow, HIGH);
    delay(1);
  }
}
