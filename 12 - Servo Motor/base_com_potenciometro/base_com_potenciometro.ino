//Bibliotecas
#include <Servo.h> 

//Variáveis de conexão
const int pot = A5; //Potenciômetro

//Variáveis globais
int leitura;


//Configs
Servo servo_motor;
void setup() {
  Serial.begin(9600);
  //Configurando os pinos do potenciômetro e do servo.
  pinMode(pot, INPUT);
  servo_motor.attach(9);
}
void loop() {
  //Remapeia o valor analógico do potênciometro para valor aceitados pelo servo.
  leitura = analogRead(pot);
  leitura = map(leitura, 0, 1023, 10, 170);

  Serial.println(leitura);
  servo_motor.write(leitura); //Escreve para o servo o valor coletado e remapeado do potenciômetro.

  delay(100);
}
