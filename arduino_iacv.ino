int piezoPin = 12; //  piezo speaker pin
int relayPin = 2;  //  relay for solenoid pin
int thermistorPin = A5; // thermistor pin
int Vo_1, Vo_2, Vo_3;  // signal readings
int Vo; // filtered signal
int warm = 370; // high bound of Vo for warm engine
int overheating = 150; // high bound of Vo for overheating engine
bool jobDone = false;

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(piezoPin, OUTPUT);
  pinMode(thermistorPin, INPUT);
  digitalWrite(relayPin, HIGH);
  tone(piezoPin, 440, 125); delay(125);
  tone(piezoPin, 493, 125); delay(125);
  tone(piezoPin, 659, 250); delay(250);
}

void loop() {
  if (jobDone == true) {
    return;
  }
  Vo_1 = analogRead(thermistorPin); 
  delay(1500);
  Vo_2 = analogRead(thermistorPin);
  delay(1500);
  Vo_3 = analogRead(thermistorPin);
  // average 3 readings to filter noise
  Vo = (Vo_1 + Vo_2 + Vo_3) / 3; 
  if (Vo < overheating) {
    overheatingAlert();
  }
  if (Vo < warm) {
    closeValve();
  }
}

void closeValve() {
  // melody to alert driver of impending closure
  tone(piezoPin, 659, 125); delay(125);
  tone(piezoPin, 493, 125); delay(125);
  tone(piezoPin, 440, 2000); delay(2000);
  digitalWrite(relayPin, LOW);
  jobDone = true;
}

void overheatingAlert() {
  // annoying noise to alert driver engine is overheating
  tone(piezoPin, 440, 20000);
  jobDone = true;
}
