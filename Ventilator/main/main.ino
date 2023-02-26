//Bibliotecas

//Configurações e variáveis
const int pinoVENTILADOR = 9;
const int frequencia = 1000;
const int pinoBOTAO = 11;
const int pinoLED_vermelho = 13;
const int pinoLED_verde = 12;
const int pinoBUZZER = 10;
int ligado = 0;

void setup() {
  pinMode(pinoBOTAO, INPUT);
  pinMode(pinoLED_vermelho, OUTPUT);
  pinMode(pinoLED_verde, OUTPUT);
  pinMode(pinoBUZZER, OUTPUT);
  pinMode(pinoVENTILADOR, OUTPUT);
}

void loop() {
  if (ligado == 0){
    digitalWrite(pinoLED_vermelho, HIGH);
    digitalWrite(pinoLED_verde, LOW);
    digitalWrite(pinoVENTILADOR, LOW);
    if (digitalRead(pinoBOTAO) == HIGH){
      while (digitalRead(pinoBOTAO) == HIGH){
        delay(50);
      }
      tone(pinoBUZZER, frequencia);
      delay(500);
      noTone(pinoBUZZER);
      ligado = 1;
    }
  }
  else if (ligado == 1){
    digitalWrite(pinoLED_vermelho, LOW);
    digitalWrite(pinoLED_verde, HIGH);
    digitalWrite(pinoVENTILADOR, HIGH);
    if (digitalRead(pinoBOTAO) == HIGH){
      while(digitalRead(pinoBOTAO) == HIGH){
        delay(50);
      }
      tone(pinoBUZZER, frequencia);
      delay(500);
      noTone(pinoBUZZER);
      ligado = 0;
    }
  }
}
