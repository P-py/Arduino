// Incluindo a biblioteca DHT para comunicação com o sensor DHT
#include "DHT.h"

// Variáveis de conexão
const int pinoDHT = 9;
const int pinoRED = 11;
const int pinoGREEN = 12;
const int pinoBLUE = 13;
const int pinoBuzzer = 10;

// Variáveis globais
float temperatura;
float umidade;

DHT dht(pinoDHT, DHT11);

void setup() {
  dht.begin(); // Inicializa as funções do sensor

  pinMode(pinoRED, OUTPUT);
  pinMode(pinoGREEN, OUTPUT);
  pinMode(pinoBLUE, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
}

void loop() {
  delay(2000); // Aguarda 2000ms - 2s, tempo necessário de acordo com a documentação do sensor

  // As leituras do sensor podem chegar à 250ms e o atraso à 2s
  temperatura = dht.readTemperature();
  umidade = dht.readHumidity(); 
  // Coleta temperatura e umidade do sensor

  // Caso ocorra algum problema acenderá o LED branco
  if (isnan(umidade) or isnan(temperatura)) {
    digitalWrite(pinoRED, HIGH);
    digitalWrite(pinoGREEN, HIGH);
    digitalWrite(pinoBLUE, HIGH);
  }
  else {
    if (temperatura < 30 && temperatura > 20) {
      digitalWrite(pinoRED, LOW);
      digitalWrite(pinoGREEN, HIGH);
      digitalWrite(pinoBLUE, LOW);
      noTone(pinoBuzzer);
    }
    else if (30 < temperatura < 35 || 15 < temperatura < 20 ) {
      digitalWrite(pinoRED, HIGH);
      digitalWrite(pinoGREEN, HIGH);
      digitalWrite(pinoBLUE, LOW);
      tone(pinoBuzzer, 1000);
      delay(500);
    }

    else if (temperatura < 15 || temperatura > 35) {
      digitalWrite(pinoRED, HIGH);
      digitalWrite(pinoGREEN, LOW);
      digitalWrite(pinoBLUE, LOW);
      tone(pinoBuzzer, 2000);
      delay(1000);
    }
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print("\t");
    Serial.print("Umidade: ");
    Serial.println(umidade);
  }
}
