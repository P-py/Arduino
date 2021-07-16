//Variáveis de conexão
const int pinoPotenciometro = A0; //Pino analógico onde está o potenciômetro

//Variáveis globais
int leitura = 0; //Armazena o valor lido pelo ADC
float tensao = 0.0; //Armazena o valor de tensão

void setup() {
  Serial.begin(9600); //Iniciando a Serial 
  pinMode(pinoPotenciometro, INPUT); //Configurando o tipo de dado do pino do potenciômetro
}

void loop() {
  // Le o valor de tensão do pino do potenciometro
  leitura = analogRead(pinoPotenciometro);
  tensao = leitura * 5.0 / 1024.0; //Converte em tensão elétrica
  
  Serial.println(tensao);
  delay(100);
}
