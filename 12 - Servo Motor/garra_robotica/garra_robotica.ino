//Bibliotecas
#include <Servo.h>

//Variáveis de conexão
const int SW = 2;
const int pinSERVO = 9;
const int VRY = A4;
const int VRX = A5;

//Variáveis globais
const int CLOSE = 170;
const int OPEN = 90; 
int leituraVRX, leituraVRY, leituraSW;
int posi_atual = 520;
boolean abrir = 0;
boolean fechar = 0;

//Config
Servo servo_motor;

void setup() {
  //Configurando os pinos
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP);
  servo_motor.attach(pinSERVO);
}

void loop() {
  leituraVRY = analogRead(VRY);
  leituraVRX = analogRead(VRX);
  leituraVRX = map(leituraVRX, 0, 1023, OPEN, CLOSE);
  servo_motor.write(leituraVRX);
  delay(10);

  if (leituraVRY >= 550) {
    abrir = 1;
  }
  else if (leituraVRY <= 490) {
    fechar = 1;
  }
  while (abrir == 1) {
    leituraVRY = analogRead(VRY);
    leituraSW = digitalRead(SW);

    if (leituraSW == HIGH) {
      if (leituraVRY > posi_atual) {
        posi_atual = leituraVRY;
        leituraVRY = map(leituraVRY, 0, 1023, CLOSE, OPEN);
        servo_motor.write(leituraVRY);
      }
    }
    else {
      abrir = 0;
      posi_atual = 520;
    }
  }
  while (fechar == 1) {
    leituraVRY = analogRead(VRY);
    leituraSW = digitalRead(SW);

    if (leituraSW == HIGH) {
      if (leituraVRY < posi_atual) {
        posi_atual = leituraVRY;
        leituraVRY = map(leituraVRY, 0, 1023, CLOSE, OPEN);
        servo_motor.write(leituraVRY);
      }
    }
    else {
      fechar = 0;
      posi_atual = 520;
    }
  }
}
