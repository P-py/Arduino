// Variáveis de conexão
const int pinoA = 12;
const int pinoB = 9;
const int pinoC = 10;
const int pinoD = 11;

void setup() {
  // Configuração dos pinos
  pinMode(pinoA, OUTPUT);
  pinMode(pinoB, OUTPUT);
  pinMode(pinoC, OUTPUT);
  pinMode(pinoD, OUTPUT);
}

void loop() {
  digitalWrite(pinoA, LOW);
  digitalWrite(pinoB, LOW);
  digitalWrite(pinoC, LOW);
  digitalWrite(pinoD, LOW);
  delay(1000);
}
