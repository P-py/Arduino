// Variáveis de conexão
const int pinoPotenciometro = A0;
const int pinoLED = 9;

// Variáveis globais
float tensao = 0.0; // Irá armazenar a tensão transferida para o led
float leitura = 0.0; //Armazena a leitura

void setup() {
  Serial.begin(9600);
  pinMode(pinoPotenciometro, INPUT);
  pinMode(pinoLED, OUTPUT);
}

void loop() {
  // Coleta o valor do potenciômetro
  leitura = analogRead(pinoPotenciometro);

  tensao = map(leitura, 0, 1023, 0, 255);
  
  // Manda um sinal analógico para o LED
  analogWrite(pinoLED, tensao);

  // Plotta/Imprime o valor de leitura, que o mesmo que determina a foça do LED
  //Serial.print("Força do LED: ");
  Serial.println(tensao);
  delay(100);
}
