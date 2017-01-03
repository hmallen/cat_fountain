/*
   Automatic drinking fountain for cats
*/

const int pirPin = 6;
const int pumpRelay = 7;
const int fountainTimeout = 10000; // Time in milliseconds of no motion detection before water shutoff

unsigned long pirStart;

void setup() {
  pinMode(pumpRelay, OUTPUT); digitalWrite(pumpRelay, LOW);

  Serial.begin(9600);
}

void loop() {
  int pirVal = analogRead(pirPin);
  Serial.println(pirVal);

  if (pirVal > 300) {
    pirStart = millis();
    digitalWrite(pumpRelay, HIGH);
    Serial.println("Relay HIGH");

    for (pirStart = millis; (millis() - pirStart) < fountainTimeout; ) {
      pirVal = analogRead(pirPin);
      Serial.println(pirVal);
      if (pirVal > 300) pirStart = millis();
      delay(1000);
    }

    digitalWrite(pumpRelay, LOW);
    Serial.println("Relay LOW");
  }

  delay(1000);
}
