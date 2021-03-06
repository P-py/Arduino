//Variáveis de conexão
const int pinoLDR = A0;
const int pinoBuzzer = 9;
const int pinoBttn = 8;

//Variáveis
int leituraLDR = 0;
int leituraBttn;

void setup() {
  //Configurando os pinos
  Serial.begin(9600);
  pinMode(pinoLDR, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoBttn, INPUT_PULLUP);
}

void loop() {
  //Coleta o vlaor de tensão no LDR
  leituraLDR = analogRead(pinoLDR);
  //Coleta o estado do botão
  leituraBttn = digitalRead(pinoBttn);

  Serial.print("Leitura de luminosidade: ");
  Serial.print(leituraLDR);
  Serial.print("\t");

  Serial.print("Obstáculo detectado: ");

  if (leituraLDR <= 512) {
    tone(pinoBuzzer, 1000); //Aciona o Buzzer se houver um obstáculo
    Serial.println("Sim");
  }
  else if (leituraBttn == LOW) {
    noTone(pinoBuzzer); //Desliga o buzzer caso o botão for pressionado.
  }
  else {
    Serial.println("Não");
  }
  delay(100); //Espera 100ms para uma nova coleta/leitura
}
