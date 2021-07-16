// Variáveis de conexão
const int pinoLDR = A0;
const int pinoBuzzer = 9;
const int pinoBotao = 8;

// Variáveis
int leituraLDR = 0;
int contador = 0;
int leituraBotao;
int flag = 0;


void setup() {
  // Configurando os pinos e o serial monitor
  pinMode(pinoLDR, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoBotao, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // Coletando o valor de tensão no LDR
  leituraLDR = analogRead(pinoLDR);

  // Coletando o estado do botão
  leituraBotao = digitalRead(pinoBotao);

  if (leituraBotao == LOW) {
    contador = 0;
    Serial.println(contador);
    delay(100);
  }

  if (leituraLDR <=512 && flag == 0) {
    contador ++;
    flag = 1;
    tone(pinoBuzzer, 1000);
    delay(100);
    noTone(pinoBuzzer);
  }

  else if (leituraLDR > 512 && flag == 1) {
    flag = 0;
  }
  Serial.print("Objetos contados: ");
  Serial.print(contador);
  Serial.print("\t");
  Serial.print("Luminosidade: ");
  Serial.println(leituraLDR);
  delay(50);
}
