//Variáveis de conexão
const int pinoLEDR = 11;
const int pinoLEDG = 10;
const int pinoLEDB = 9;
const int pinoLEDW = 8;
char leitura;

void setup() {
  Serial.begin(9600);
  Serial.println("Digite um número sendo 1 ou 0");
  pinMode(pinoLEDR, OUTPUT);
  pinMode(pinoLEDG, OUTPUT);
  pinMode(pinoLEDB, OUTPUT);
  pinMode(pinoLEDW, OUTPUT);
}

void loop() {
  if (Serial.available() > 0 ) {
    leitura = Serial.read();
    //leitura = leitura-48;
    Serial.println(leitura);
    if (leitura == '1') {
      digitalWrite(pinoLEDW, HIGH);
      analogWrite(pinoLEDR, 150);
      analogWrite(pinoLEDG, 255);
      analogWrite(pinoLEDB, 255);
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
    }
    if (leitura == '2') {
      digitalWrite(pinoLEDW, HIGH);
      analogWrite(pinoLEDR, 0);
      analogWrite(pinoLEDG, 0);
      analogWrite(pinoLEDB, 0);
    }
    if (leitura == '4') {
      digitalWrite(pinoLEDW, LOW);
      analogWrite(pinoLEDR, 255);
      analogWrite(pinoLEDG, 0);
      analogWrite(pinoLEDB, 0);
    }
    if (leitura == '5') {
      digitalWrite(pinoLEDW, LOW);
      analogWrite(pinoLEDR, 0);
      analogWrite(pinoLEDG, 255);
      analogWrite(pinoLEDB, 0);
    }
    if (leitura == '6') {
      digitalWrite(pinoLEDW, LOW);
      analogWrite(pinoLEDR, 0);
      analogWrite(pinoLEDG, 0);
      analogWrite(pinoLEDB, 255);
    }
  }
  delay(100);
}
