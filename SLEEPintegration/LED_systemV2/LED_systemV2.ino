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

void setup() {
  Serial.begin(9600);
  Serial.println("Digite um número sendo 1 ou 0");
  pinMode(pinoLEDR, OUTPUT);
  pinMode(pinoLEDG, OUTPUT);
  pinMode(pinoLEDB, OUTPUT);
  pinMode(pinoLEDW, OUTPUT);
  pinMode(bttn, INPUT_PULLUP);
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
    Serial.println(leitura);
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
    if (leitura == '7') {
      digitalWrite(pinoLEDW, LOW);
      analogWrite(pinoLEDR, 75);
      analogWrite(pinoLEDG, 0);
      analogWrite(pinoLEDB, 150);
      flag = HIGH;
    }
    if (leitura == '8') {
      digitalWrite(pinoLEDW, LOW);
      analogWrite(pinoLEDR, 190);
      analogWrite(pinoLEDG, 100);
      analogWrite(pinoLEDB, 0);
      flag = HIGH;
    }
  }
  delay(100);
}
