const int pinoLDR = A0;
int leitura = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinoLDR, INPUT);
}

void loop() {
  leitura = analogRead(pinoLDR);

  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print("\t");

  Serial.print("Obstaculo: ");
  if (leitura <= 512) {
    Serial.println("Sim");
  }
  else {
    Serial.println("Não");
  }
  delay(500); 
}
