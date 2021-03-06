// Variáveis de conexão
const int trig = 3;
const int echo = 2;
const int distancia_obstaculo = 20;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  int distancia = sensor_morcego(trig, echo);
  if (distancia <= distancia_obstaculo) {
    Serial.print("Com obstáculo: ");
    Serial.print(distancia);
    Serial.println("cm");
  }
  else {
    Serial.print("Sem obstáculo: ");
    Serial.print(distancia);
    Serial.println("cm");
  }
  delay(200);
}

int sensor_morcego(int pinotrig, int pinoecho) {
  digitalWrite(pinotrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig, LOW);

  return pulseIn(pinoecho, HIGH)/58;
}
