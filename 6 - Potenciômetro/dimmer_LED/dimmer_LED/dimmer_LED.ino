//Variáveis de conexão
const int pinoPotenciometro = A0;
const int pinoLED = 12; //

//Variáveis globais
const int periodo = 1023;
int tempo_ligado, tempo_desligado; //Armazena o valor lido pelo ADC

void setup() {
  Serial.begin(9600);
  pinMode(pinoPotenciometro, INPUT);
  pinMode(pinoLED, OUTPUT);
}

void loop() {
  tempo_ligado = analogRead(pinoPotenciometro); //Valor de tensão no pino do potenciômetro
  tempo_desligado = periodo - tempo_ligado; //Recebe quanto tempo o LED deverá permanecer desligado

  digitalWrite(pinoLED, HIGH); // Aciona o LED
  delayMicroseconds(tempo_ligado); // Espera o valor lido pelo potenciômetro em ms
  digitalWrite(pinoLED, LOW); // Desliga o LED
  delayMicroseconds(tempo_desligado); // Espera o valor lido pelo potenciômetro em ms
  Serial.print(tempo_ligado);
  Serial.print("\t");
  Serial.println(tempo_desligado);
}
