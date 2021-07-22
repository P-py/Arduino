// Variáveis de conexão
const int trig = 3;
const int echo = 2;
const int pinoBuzzer = 7;
// Variáveis globais
const int distancia_obstaculo = 50;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
}

void loop() {
  int distancia = sensor_morcego(trig, echo);
  if (distancia <= distancia_obstaculo) {
    Serial.print("Com obstáculo: ");
    Serial.print(distancia);
    Serial.println("cm");
    tone(pinoBuzzer, 2500);
  }
  else {
    Serial.print("Sem obstáculo: ");
    Serial.print(distancia);
    Serial.println("cm");
    noTone(pinoBuzzer);
  }
  delay(100);
}

int sensor_morcego(int pinotrig, int pinoecho) {
  digitalWrite(pinotrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig, LOW);

  return pulseIn(pinoecho, HIGH)/58;
}
