//Variáveis de conexão
const int pinoLED = 7;
char leitura;

void setup() {
  Serial.begin(9600);
  Serial.println("Digite um número sendo 1 ou 0");
  pinMode(pinoLED, OUTPUT);
}

void loop() {
  if (Serial.available()>0){
    leitura = Serial.read();
    //leitura = leitura-48;
    Serial.println(leitura);
    if (leitura == '1'){
      digitalWrite(pinoLED, HIGH);
    }
    if (leitura == '0') {
      digitalWrite(pinoLED, LOW);
    }
  }
    delay(100);
}
