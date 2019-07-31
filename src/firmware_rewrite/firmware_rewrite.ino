#include <Bounce2.h>

int colPin = 7;
int colPin2 = 8;
int colPin3 = 16;
int colPin4 = 17;
int colPin5 = 18;

int colPins[] = {7, 8, 16, 17, 18};

int row1Pin = 2;
int row2Pin = 3;

int rowPins[] = {row1Pin, row2Pin};

Bounce colBounce = Bounce();
Bounce colBounce2 = Bounce();
Bounce colBounce3 = Bounce();
Bounce colBounce4 = Bounce();
Bounce colBounce5 = Bounce();

Bounce *keys[] = {&colBounce, &colBounce2, &colBounce3, &colBounce4, &colBounce5};

void setup() {
  pinMode(row1Pin, OUTPUT);
  digitalWrite(row1Pin, HIGH);
  pinMode(row2Pin, OUTPUT);
  digitalWrite(row2Pin, HIGH);

  pinMode(colPin, INPUT_PULLUP);
  pinMode(colPin2, INPUT_PULLUP);
  pinMode(colPin3, INPUT_PULLUP);
  pinMode(colPin4, INPUT_PULLUP);
  pinMode(colPin5, INPUT_PULLUP);
  
  colBounce.attach(colPin);
  colBounce.interval(1);

  colBounce2.attach(colPin2);
  colBounce2.interval(1);

  colBounce3.attach(colPin3);
  colBounce3.interval(1);

  colBounce4.attach(colPin4);
  colBounce4.interval(1);
  
  colBounce5.attach(colPin5);
  colBounce5.interval(1);

  Serial.begin(9600);
  while (!Serial) {;}

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(row1Pin, LOW);
  digitalWrite(row2Pin, HIGH);

//  Serial.printf("%x\n", &colBounce);

  for (int i = 0; i < 5; i++) {
    Bounce *key = keys[i];

    key->update();

    if (key->fell()) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
  
  digitalWrite(row1Pin, HIGH);
  digitalWrite(row2Pin, LOW);
  
  delay(10);
}
