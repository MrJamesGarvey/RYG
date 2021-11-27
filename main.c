

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)




void setup() {
  // set the digital pin as output:
  Serial.begin(9600);
  for (int i = 2; i <= 7; i++) {
    pinMode(i, OUTPUT);
  }
  for (int i = 8; i <= 13; i++) {
    pinMode(i, INPUT);
  }

}


int blink(int buttonNmuber, int delayOn, int delayOff, int ledNumber, int loopLength) {
  int a = loopLength;

  if (digitalRead(buttonNmuber) == HIGH) {
    while (a > 0) {
      delay(delayOn);
      digitalWrite(ledNumber, HIGH);
      delay(delayOff);
      digitalWrite(ledNumber, LOW);

      Serial.print("Button number: ");
      Serial.println(digitalRead(buttonNmuber));
      delay(100);
      Serial.print("LED number: ");
      Serial.println(digitalRead(ledNumber));
      delay(100);
      a--;
    }
  }

}

void loop() {

  blink(8, 1000, 1000, 2, 3);
  blink(9, 1000, 1000, 3, 3);
  blink(10, 1000, 1000, 4, 3);

}
