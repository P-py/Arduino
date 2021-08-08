//Bibliotecas
#include <Servo.h>

//Config
Servo servo_motor;

void setup() {
  //Informa em qual pino o servo será usado
  servo_motor.attach(9);

  servo_motor.write(10);
  //Informa ao servo que deve se posicionar em 10°
}

void loop() {
  //Vazio
}
