//Variáveis
int frequency = 2000; //Frequência inicial padrão
const int pinoBuzzer = 10; //Constante que determina o pino onde está conectado o buzzer.
const int pinoBttn1 = 9; //Constante que determina o pino onde está conectado o botão 1.
const int pinoBttn2 = 11; //Constante que determina o pino onde está conectado o botão 2.

void setup() {
  pinMode(pinoBuzzer, OUTPUT); //Configura o pino digital do buzzer como saída de dados.
  pinMode(pinoBttn1, INPUT_PULLUP); //Configura o pino digital do botão como entrada de dados.
  pinMode(pinoBttn2, INPUT_PULLUP); //Configura o pino digital do botão como entrada de dados.
}

void loop() {
  //Soma 100 à frequência se o botão estiver pressionado.
  if (digitalRead(pinoBttn1) == LOW) {
    frequency = frequency + 100;
  }
  //Subtrai 100 da frequência se o botão estiver pressionado. 
  if (digitalRead(pinoBttn2) == LOW) {
    frequency = frequency - 100;
  }

  tone(pinoBuzzer, frequency); //Gera frequência para o buzzer.
  delay(1500);
  noTone(pinoBuzzer); //Para de produzir frequência para o buzzer.
  delay(1500);
}
