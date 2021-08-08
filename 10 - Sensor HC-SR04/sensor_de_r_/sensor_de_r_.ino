//Variáveis de conexão
const int pinoA = 12;
const int pinoB = 9;
const int pinoC = 10;
const int pinoD = 11;

const int LED10M = 7;
const int LED20M = 6;
const int LED30M = 5;
const int LED40M = 4;

const int TRIG = 3;
const int ECHO = 2;
int distancia, dec_distancia, uni_distancia;

//Config
void setup() {
  //Serial startup
  Serial.begin(9600);

  pinMode(pinoA, OUTPUT);
  pinMode(pinoB, OUTPUT);
  pinMode(pinoC, OUTPUT);
  pinMode(pinoC, OUTPUT);
  pinMode(pinoD, OUTPUT);
  pinMode(LED10M, OUTPUT);
  pinMode(LED20M, OUTPUT);
  pinMode(LED30M, OUTPUT);
  pinMode(LED40M, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

//Loop
void loop() {
  distancia = sensor_morcego(TRIG, ECHO);
  dec_distancia = distancia/100;
  uni_distancia = (((distancia/100.00) - dec_distancia)*10);
  Serial.println(distancia);

  switch (uni_distancia) {
    case 0:
      digitalWrite(pinoA, LOW);
      digitalWrite(pinoB, LOW);
      digitalWrite(pinoC, LOW);
      digitalWrite(pinoD, LOW);
      break;
    case 1:
      digitalWrite(pinoA, HIGH);
      digitalWrite(pinoB, LOW);
      digitalWrite(pinoC, LOW);
      digitalWrite(pinoD, LOW);
      break;
    case 2:
      digitalWrite(pinoA, LOW);
      digitalWrite(pinoB, HIGH);
      digitalWrite(pinoC, LOW);
      digitalWrite(pinoD, LOW);
      break;
    case 3:
      digitalWrite(pinoA, HIGH);
      digitalWrite(pinoB, HIGH);
      digitalWrite(pinoC, LOW);
      digitalWrite(pinoD, LOW);
      break;
    case 4:
      digitalWrite(pinoA, LOW);
      digitalWrite(pinoB, LOW);
      digitalWrite(pinoC, HIGH);
      digitalWrite(pinoD, LOW);
      break;
    case 5:
      digitalWrite(pinoA, HIGH);
      digitalWrite(pinoB, LOW);
      digitalWrite(pinoC, HIGH);
      digitalWrite(pinoD, LOW);
      break;
    case 6:
      digitalWrite(pinoA, LOW);
      digitalWrite(pinoB, HIGH);
      digitalWrite(pinoC, HIGH);
      digitalWrite(pinoD, LOW);
      break;
    case 7:
      digitalWrite(pinoA, HIGH);
      digitalWrite(pinoB, HIGH);
      digitalWrite(pinoC, HIGH);
      digitalWrite(pinoD, LOW);
      break;
    case 8:
      digitalWrite(pinoA, LOW);
      digitalWrite(pinoB, LOW);
      digitalWrite(pinoC, LOW);
      digitalWrite(pinoD, HIGH);
      break;
    case 9:
      digitalWrite(pinoA, HIGH);
      digitalWrite(pinoB, LOW);
      digitalWrite(pinoC, LOW);
      digitalWrite(pinoD, HIGH);
      break;
  }
  switch (dec_distancia) {
    case 0:
      digitalWrite(LED10M, LOW);
      digitalWrite(LED20M, LOW);
      digitalWrite(LED30M, LOW);
      digitalWrite(LED40M, LOW);
      break;
    case 1:
      digitalWrite(LED10M, HIGH);
      digitalWrite(LED20M, LOW);
      digitalWrite(LED30M, LOW);
      digitalWrite(LED40M, LOW);
      break;
    case 2:
      digitalWrite(LED10M, LOW);
      digitalWrite(LED20M, HIGH);
      digitalWrite(LED30M, LOW);
      digitalWrite(LED40M, LOW);
      break;
    case 3:
      digitalWrite(LED10M, LOW);
      digitalWrite(LED20M, LOW);
      digitalWrite(LED30M, HIGH);
      digitalWrite(LED40M, LOW);
      break;
    case 4:
      digitalWrite(LED10M, LOW);
      digitalWrite(LED20M, LOW);
      digitalWrite(LED30M, LOW);
      digitalWrite(LED40M, HIGH);
      break;
  }
  delay(100);
}

//HC-SR04 data processing function
int sensor_morcego(int pinotrig, int pinoecho) {
  digitalWrite(pinotrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig, LOW);

  return pulseIn(pinoecho, HIGH)/59;
}
