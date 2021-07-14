//Vairáveis de conexão
const int pino_bttn1 = 7;
const int pino_bttn2 = 8;
const int pino_bttn3 = 9;
const int pino_buzzer = 10;
const int pino_led1 = 11;
const int pino_led2 = 12;
const int pino_led3 = 13;

//Variáveis referentes à frequência de cada nota
const int c = 261; //Dó
const int d = 293; //Ré
const int e = 329; //Mi
const int f = 349; //Fá
const int g = 391; //Sol
const int a = 440; //Lá
const int b = 493; //Si 

void setup() {
  //Configurando o tipo de dado de cada pino
  pinMode(pino_bttn1, INPUT_PULLUP);
  pinMode(pino_bttn2, INPUT_PULLUP);
  pinMode(pino_bttn3, INPUT_PULLUP);
  pinMode(pino_buzzer, OUTPUT);
  pinMode(pino_led1, OUTPUT);
  pinMode(pino_led2, OUTPUT);
  pinMode(pino_led3, OUTPUT);
}

void loop() {
  //Armazena em uma variável booleana o estado de cada botão.
  bool estado_bttn1 = digitalRead(pino_bttn1);
  bool estado_bttn2 = digitalRead(pino_bttn2);
  bool estado_bttn3 = digitalRead(pino_bttn3);

  if (estado_bttn1 == LOW) {
    tone(pino_buzzer, c); //Toca a nota Dó
    digitalWrite(pino_led1, HIGH);
    digitalWrite(pino_led2, LOW);
    digitalWrite(pino_led3, LOW);
  }
  else if (estado_bttn2 == LOW) {
    tone(pino_buzzer, d); //Toca a nota Ré
    digitalWrite(pino_led1, LOW);
    digitalWrite(pino_led2, HIGH);
    digitalWrite(pino_led3, LOW);
  }
  else if (estado_bttn3 == LOW) {
    tone(pino_buzzer, e); //Toca a nota Mi
    digitalWrite(pino_led1, LOW);
    digitalWrite(pino_led2, LOW);
    digitalWrite(pino_led3, HIGH);
  }
  else {
    noTone(pino_buzzer); //Desliga o buzzer
    digitalWrite(pino_led1, LOW);
    digitalWrite(pino_led2, LOW);
    digitalWrite(pino_led3, LOW);
  }
}
