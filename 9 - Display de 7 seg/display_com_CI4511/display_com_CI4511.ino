// A função principal do circuito integrado CI4511 é traduzir/converter BCD para o display de 7 seg.

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
  // Liga os bits necessários para formar 0 = 0000
  digitalWrite(pinoA, LOW);
  digitalWrite(pinoB, LOW);
  digitalWrite(pinoC, LOW);
  digitalWrite(pinoD, LOW);
  delay(1000);

  // Liga os bits necessários para formar 1 = 0001
  digitalWrite(pinoA, HIGH);
  digitalWrite(pinoB, LOW);
  digitalWrite(pinoC, LOW);
  digitalWrite(pinoD, LOW);
  delay(1000);

  // Liga os bits necessários para formar 2 = 0010
  digitalWrite(pinoA, LOW);
  digitalWrite(pinoB, HIGH);
  digitalWrite(pinoC, LOW);
  digitalWrite(pinoD, LOW);
  delay(1000);

  // Liga os bits necessários para formar 3 = 0011
  digitalWrite(pinoA, HIGH);
  digitalWrite(pinoB, HIGH);
  digitalWrite(pinoC, LOW);
  digitalWrite(pinoD, LOW);
  delay(1000);

  // Liga os bits necessários para formar 4 = 0100
  digitalWrite(pinoA, LOW);
  digitalWrite(pinoB, LOW);
  digitalWrite(pinoC, HIGH);
  digitalWrite(pinoD, LOW);
  delay(1000);

  // Liga os bits necessários para formar 5 = 0101
  digitalWrite(pinoA, HIGH);
  digitalWrite(pinoB, LOW);
  digitalWrite(pinoC, HIGH);
  digitalWrite(pinoD, LOW);
  delay(1000);

  // Liga os bits necessários para formar 6 = 0110
  digitalWrite(pinoA, LOW);
  digitalWrite(pinoB, HIGH);
  digitalWrite(pinoC, HIGH);
  digitalWrite(pinoD, LOW);
  delay(1000);

  // Liga os bits necessários para formar 7 = 0111
  digitalWrite(pinoA, HIGH);
  digitalWrite(pinoB, HIGH);
  digitalWrite(pinoC, HIGH);
  digitalWrite(pinoD, LOW);
  delay(1000);

  // Liga os bits necessários para formar 8 = 1000
  digitalWrite(pinoA, LOW);
  digitalWrite(pinoB, LOW);
  digitalWrite(pinoC, LOW);
  digitalWrite(pinoD, HIGH);
  delay(1000);

  // Liga os bits necessários para formar 9 = 1001
  digitalWrite(pinoA, HIGH);
  digitalWrite(pinoB, LOW);
  digitalWrite(pinoC, LOW);
  digitalWrite(pinoD, HIGH);
  delay(1000);
}
