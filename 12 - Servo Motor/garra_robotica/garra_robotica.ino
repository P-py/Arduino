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
  Serial.begin(9600);
  //Configurando os pinos
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP);
  servo_motor.attach(pinSERVO);
}

void loop() {
  leituraVRX = analogRead(VRX);

  if (leituraVRX >= 545) {
    leituraVRX = map(leituraVRX, 0, 1023, OPEN, CLOSE);
    servo_motor.write(10);
    Serial.println(leituraVRX);
  }
  else if (leituraVRX <= 475) {
    leituraVRX = map(leituraVRX, 0, 1023, OPEN, CLOSE);
    servo_motor.write(100);
    Serial.println(leituraVRX);
  }

  else {
    Serial.println(leituraVRX);
  }

  delay(100  );
}
