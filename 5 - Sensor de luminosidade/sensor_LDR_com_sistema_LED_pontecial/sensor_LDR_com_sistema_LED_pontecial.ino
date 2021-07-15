const int pinoLDR = A0;
const int pinoLED_VM = 7;
const int pinoLED_VR = 5;
const int pinoLED_AM = 6;
const int pinoBuzzer = 10;
int leitura = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinoLDR, INPUT);
  pinMode(pinoLED_VM, OUTPUT);
  pinMode(pinoLED_AM, OUTPUT);
  pinMode(pinoLED_VR, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
}

void loop() {
  leitura = analogRead(pinoLDR);
  Serial.print("Leitura: ");
  Serial.println(leitura);

  if (leitura < 100) {
    Serial.println("Luminosidade em baixo nível");
    digitalWrite(pinoLED_VR, HIGH);
    delay(500);
    digitalWrite(pinoLED_AM, HIGH);
    delay(500);
    digitalWrite(pinoLED_VM, HIGH);
    tone(pinoBuzzer, 500);
  }
  else if (leitura < 500 && leitura >= 100) {
    Serial.println("Luminosidade em nível médio");
    digitalWrite(pinoLED_VR, HIGH);
    delay(500);
    digitalWrite(pinoLED_AM, HIGH);
    delay(500);
    digitalWrite(pinoLED_VM, LOW);
  }
  else if (leitura > 500) {
    Serial.println("Luminosidade em nível satisfatírio");
    digitalWrite(pinoLED_VR, HIGH);
    delay(500);
    digitalWrite(pinoLED_AM, LOW);
    delay(500);
    digitalWrite(pinoLED_VM, LOW);
  }
  delay(5000);
  noTone(pinoBuzzer);
  digitalWrite(pinoLED_VR, LOW);
  digitalWrite(pinoLED_AM, LOW);
  digitalWrite(pinoLED_VM, LOW);
  delay(2000);
}
