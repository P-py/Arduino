//Variáveis de conexão
const int VRX = A4;
const int VRY = A5;
const int SW = 2;

//Variáveis globais
int leitura_botao = 0;
int leituraVRX, leituraVRY;

void setup() {
  //Configurando serial monitor.
  Serial.begin(9600);

  //Configurando os pinos
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() {
  leituraVRX = analogRead(VRX);
  leituraVRY = analogRead(VRY);
  leitura_botao = digitalRead(SW);

  Serial.print("Leitura em VRX: ");
  Serial.print("\t");
  Serial.print(leituraVRX);
  Serial.print("\t");
  Serial.print("Leitura em VRY: ");
  Serial.print("\t");
  Serial.print(leituraVRY);
  Serial.print("\t");
  Serial.print("Leitura do botão: ");
  Serial.println(leitura_botao);

  delay(10);
}
