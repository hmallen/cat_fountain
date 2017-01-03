/*
   Automatic drinking fountain for cats
*/

const int pirRelay = 6;
const int pumpRelay = 7;

unsigned long pirStart;

void setup() {
  pinMode(pumpRelay, OUTPUT); digitalWrite(pumpRelay, LOW);
  pinMode(pirPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  bool pirVal = digitalRead(pirPin);

  if (pirVal) {
    pirStart = millis();
    digitalWrite(pumpRelay, HIGH);

    for (pirStart = millis; (millis() - pirStart) < fountainTimeout; ) {
      if (pirVal) pirStart = millis();
      delay(500);
    }

    digitalWrite(pumpRelay, LOW);
  }
}
