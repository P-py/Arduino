//Bibliotecas
#include "DHT.h"
#include <Servo.h>

//Objeto para controle do servo
Servo servo_motor;

//Variáveis de conexão
const int pinoLEDR = 11;
const int pinoLEDG = 10;
const int pinoLEDB = 9;
const int pinoLEDW = 8;

char leitura;
const int bttn = 7;
int estado = 0;
int guarda_estado = LOW;
int flag = LOW;

const int pino_dht = 6;
DHT dht(pino_dht, DHT11);

//Variáveis globais
int temperatura;
int umidade;


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1);
  pinMode(pinoLEDR, OUTPUT);
  pinMode(pinoLEDG, OUTPUT);
  pinMode(pinoLEDB, OUTPUT);
  pinMode(pinoLEDW, OUTPUT);
  pinMode(bttn, INPUT_PULLUP);

  dht.begin();

  servo_motor.attach(5);

  servo_motor.attach(50);
}

void loop() {
  
  estado = digitalRead(bttn);

  if (estado == LOW) {
    guarda_estado = !guarda_estado;
    flag = LOW;
    while (digitalRead(bttn) == LOW) {
      delay(50);
    }
  }

  if (guarda_estado == HIGH && flag == LOW) {
    digitalWrite(pinoLEDW, HIGH);
    analogWrite(pinoLEDR, 0);
    analogWrite(pinoLEDG, 255);
    analogWrite(pinoLEDB, 255);
  }
  else if (guarda_estado == LOW && flag == LOW){
    digitalWrite(pinoLEDW, LOW);
    analogWrite(pinoLEDR, 0);
    analogWrite(pinoLEDG, 0);
    analogWrite(pinoLEDB, 0);
  }

  
  if (Serial.available() > 0 ) {
    leitura = Serial.read();
    //leitura = leitura-48;
    if (leitura == '1') {
      digitalWrite(pinoLEDW, HIGH);
      analogWrite(pinoLEDR, 150);
      analogWrite(pinoLEDG, 255);
      analogWrite(pinoLEDB, 255);
      flag = HIGH;
    }
    if (leitura == '0') {
      digitalWrite(pinoLEDW, LOW);
      analogWrite(pinoLEDR, 0);
      analogWrite(pinoLEDG, 0);
      analogWrite(pinoLEDB, 0);
    }
    if (leitura == '3') {
      digitalWrite(pinoLEDW, HIGH);
      analogWrite(pinoLEDR, 0);
      analogWrite(pinoLEDG, 255);
      analogWrite(pinoLEDB, 255);
      flag = HIGH;
    }
    if (leitura == '2') {
      digitalWrite(pinoLEDW, HIGH);
      analogWrite(pinoLEDR, 0);
      analogWrite(pinoLEDG, 0);
      analogWrite(pinoLEDB, 0);
      flag = HIGH;
    }
    if (leitura == '4') {
      digitalWrite(pinoLEDW, LOW);
      analogWrite(pinoLEDR, 255);
      analogWrite(pinoLEDG, 0);
      analogWrite(pinoLEDB, 0);
      flag = HIGH;
    }
    if (leitura == '5') {
      digitalWrite(pinoLEDW, LOW);
      analogWrite(pinoLEDR, 0);
      analogWrite(pinoLEDG, 255);
      analogWrite(pinoLEDB, 0);
      flag = HIGH;
    }
    if (leitura == '6') {
      digitalWrite(pinoLEDW, LOW);
      analogWrite(pinoLEDR, 0);
      analogWrite(pinoLEDG, 0);
      analogWrite(pinoLEDB, 255);
      flag = HIGH;
    }
    if (leitura == 't'){
      delay(2000);
      
      temperatura = dht.readTemperature();
      umidade = dht.readHumidity();

      if (isnan(umidade) or isnan(temperatura)) {
        Serial.println("Falha na leitura ou conexão do Sensor DHT!");
      }
      else {
        Serial.print(temperatura);
        Serial.print(" ºCelsius e ");
        Serial.print(umidade);
        Serial.println(" %  de umidade relativa do ar.");
      }
    }
    if (leitura == '7') {
      digitalWrite(pinoLEDW, LOW);
      digitalWrite(pinoLEDR, 75);
      digitalWrite(pinoLEDG, 0);
      digitalWrite(pinoLEDB, 150);
      flag = HIGH;
    }
    if (leitura == 'n') {
      
    }
  }
  delay(100);
}
