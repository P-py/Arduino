#include "DHT.h" // Incluindo a biblioteca para comunicação com o sensor.

//Variáveis de conexão
const int pino_dht = 9; // Sensor DHT
const int pino_a = 12;
DHT dht(pino_dht, DHT11); // Função da biblioteca DHT, define o pino e qual versão do DHT

//Variáveis globais
float temperatura; // Armazenará o valor de temperatura
float umidade; // Armazenará o valor de umidade 

void setup() {
  Serial.begin(9600);
  dht.begin(); // Inicializa as funções do sensor
  pinMode(pino_a, OUTPUT);
}

void loop() {
  delay(2000); // Aguarda 2 segundos (necessário de acordo com a documentação do sensor)

  // A leitura pode levar até 250ms
  // O atraso pode levar até 2000ms - 2s
  temperatura = dht.readTemperature(); // Coleta a temperatura em Celsius
  umidade = dht.readHumidity();

  // Verifica se houve alguma falha na conexão/leitura do sensor.
  // A função isnan verifica se o valor nos parêntesis é número ou não.
  if (isnan(umidade) or isnan(temperatura)) {
    Serial.println("Falha na leitura ou conexão do Sensor DHT!");
  }
  
  else {
    // Imprime os valores
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" ºC \t");
    
    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.println(" % \t"); 
  }
  digitalWrite(pino_a, HIGH);
  delay(100);
  digitalWrite(pino_a, LOW);
}
