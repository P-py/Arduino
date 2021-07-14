void setup() {
  pinMode(12, OUTPUT); //Configura o pino digital 12 (LED) como saída de dados.
  pinMode(11, INPUT); //Configura o pino digital 11 (Botão) como entrada de dados.
  pinMode(10, OUTPUT); //LED
  pinMode(9, INPUT); //Botão  
}
void loop() {
  if (digitalRead(11) == HIGH){
    digitalWrite(12, HIGH);
  }
  else {
    digitalWrite(12, LOW);
  }
  if (digitalRead(9) == HIGH) {
    digitalWrite(10, LOW);
  }
  else {
    digitalWrite(10, HIGH);
  }
}
