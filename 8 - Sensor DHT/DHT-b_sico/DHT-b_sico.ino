#include "DHT.h"

//Variáveis de conexão
const int pino_dht = 9;
float temperatura;
float umidade;
DHT dht(pino_dht, DHT11); 

//Variáveis globais

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
