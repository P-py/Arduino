// Variáveis de conexão
const int pinoA = 12;
const int pinoB = 9;
const int pinoC = 10;
const int pinoD = 11;

// Variáveis globais
char leitura_serial;

void setup() {
  // Configurando os pinos
  pinMode(pinoA, OUTPUT);
  pinMode(pinoB, OUTPUT);
  pinMode(pinoC, OUTPUT);
  pinMode(pinoD, OUTPUT);

  // Iniciando e configurando a serial
  Serial.begin(9600);
  Serial.println("Digite um número de 0 a 9");
}

void loop() {
  // put your main code here, to run repeatedly:

}
