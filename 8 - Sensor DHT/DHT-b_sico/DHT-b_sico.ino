#include "DHT.h" // Incluindo a biblioteca para comunicação com o sensor.

//Variáveis de conexão
const int pino_dht = 9; // Sensor DHT
DHT dht(pino_dht, DHT11); // Função da biblioteca DHT, define o pino e qual versão do DHT

//Variáveis globais
float temperatura; // Armazenará o valor de temperatura
float umidade; // Armazenará o valor de umidade 

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);

  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Falha na leitura do Sensor DHT!");
  }
  
  else { // Se não
    // Imprime o valor de temperatura  
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" *C ");
    
    Serial.print("\t"); // tabulação
  
    // Imprime o valor de umidade
    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.print(" %\t"); 
    
    Serial.println(); // nova linha
  }
}
