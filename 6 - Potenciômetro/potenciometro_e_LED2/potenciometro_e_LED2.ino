// Variáveis de conexão
const int pinoPotenciometro = A0;
const int pinoLED = 11;

// Variáveis globais
int leitura = 0; // Armazena o valor lido pelo ADC
int pwm = 0; // Armazena o valor da razão cíclica (duty cicle)

void setup() {
  pinMode(pinoPotenciometro, INPUT);
  pinMode(pinoLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Coleta o valor do potenciômetro
  leitura = analogRead(pinoPotenciometro);

  // Converte a escala de valor de 0~1023 para 0~255
  pwm = map(leitura, 0, 1023, 0, 255);

  // Atualiza a razão cíclica do pino 11, variando a intensidade do LED
  analogWrite(pinoLED, pwm);
  
  Serial.println(pwm);
}
