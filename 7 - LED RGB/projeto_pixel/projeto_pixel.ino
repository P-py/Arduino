// Variáveis de conexão
const int pinoRED = 11;
const int pinoGREEN = 10;
const int pinoBLUE = 9;
const int pinoBttnR = 7;
const int pinoBttnG = 6;
const int pinoBttnB = 5;

// Variáveis globais
int BttnR;
int BttnG;
int BttnB;

void setup() {
  pinMode(pinoRED, OUTPUT);
  pinMode(pinoGREEN, OUTPUT);
  pinMode(pinoBLUE, OUTPUT);
  pinMode(pinoBttnR, INPUT_PULLUP);
  pinMode(pinoBttnG, INPUT_PULLUP);
  pinMode(pinoBttnB, INPUT_PULLUP);
}

void loop() {
  BttnR = digitalRead(pinoBttnR);
  BttnG = digitalRead(pinoBttnG);
  BttnB = digitalRead(pinoBttnB);

  if (BttnR == LOW) {
    analogWrite(pinoRED, 255);
  }
  else {
    analogWrite(pinoRED, 0);
  }

  if (BttnG == LOW) {
    analogWrite(pinoGREEN, 255);
  }
  else {
    analogWrite(pinoGREEN, 0);
  }

  if (BttnB == LOW) {
    analogWrite(pinoBLUE, 255);
  }
  else {
    analogWrite(pinoBLUE, 0);
  }
  
  delay(100);
}
