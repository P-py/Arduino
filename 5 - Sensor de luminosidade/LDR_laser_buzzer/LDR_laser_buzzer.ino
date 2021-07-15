//Variáveis de conexão
const int pinoLDR = A0;
const int pinoBuzzer = 9;
const int pinoBttn = 8;

//Variáveis
int leituraLDR = 0;
int leituraBttn;

void setup() {
  //Configurando os pinos
  pinMode(pinoLDR, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoBttn, INPUT_PULLUP);
}

void loop() {
  //Coleta o vlaor de tensão no LDR
  leituraLDR = analogRead(pinoLDR);
  //Coleta o estado do botão
  leituraBttn = digitalRead(pinoBttn);

  if (leituraLDR <= 512) {
    tone(pinoBuzzer, 1000); //Aciona o Buzzer se houver um obstáculo
  }
  else if (leituraBttn == LOW) {
    noTone(pinoBuzzer); //Desliga o buzzer caso o botão for pressionado.
  }
  delay(100); //Espera 100ms para uma nova coleta/leitura
}
