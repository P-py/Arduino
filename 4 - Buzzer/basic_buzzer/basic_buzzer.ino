//Definindo variáveis
int frequency = 1000;

void setup() {
  pinMode(10, OUTPUT); //Configurando o pino digital 10 como saída de dados.
}

void loop() {
  tone(10, frequency); //Gera frequência de 2000hz para o pino digital 10, onde está localizado o buzzer.
  delay(1000);
  noTone(10); //Para de produzir frequência.
  delay(1000);
}
