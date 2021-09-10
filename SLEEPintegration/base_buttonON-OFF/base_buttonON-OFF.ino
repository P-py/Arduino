//Base para outros projetos
//Função ON/OFF em um mesmo botão

//Conexão
const int led = 8;
const int bttn = 7;
int funcaoa = 0;
int funcaob = 0;
int estado = 0;

void setup() {
  pinMode(bttn, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  funcaoa = digitalRead(bttn);
  if ((funcaoa == LOW) && (funcaob == LOW)) {
    estado = 1 - estado;
    delay(500);
  }
  funcaob = funcaoa;
  if (estado == 1) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
