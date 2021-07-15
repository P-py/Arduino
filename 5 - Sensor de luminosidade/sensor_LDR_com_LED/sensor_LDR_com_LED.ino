//Variáveis de conexão
const int pinoLDR = A0; // Pino analógico onde o sensor LDR está conectado
const int pinoLED = 7; //Pino digital onde o LED está conectado
int leitura = 0; //Variável para armazenar o valor lido pelo ADC

void setup() {
  //Configurando os pinos e o seu tipo de dado.
  Serial.begin(9600);
  pinMode(pinoLDR, INPUT);
  pinMode(pinoLED, OUTPUT);
}

void loop() {
  //Lê o valor de ADC no pino LDR
  leitura = analogRead(pinoLDR);

  //Imprine no Serial Monitor a quantida de luminosidade medida
  Serial.print("Luminosidade: ");
  Serial.println(leitura);
  
  //Verifica luminosidade do ambiente
  if (leitura < 150) {
    digitalWrite(pinoLED, HIGH); //Acende o LED caso a luminosidade do ambiente for menor que 40
  }
  else {
    digitalWrite(pinoLED, LOW); //Apaga o LED caso a condicional não for efetuada
  }
  delay(1000); //Espera 1000ms - 1s para uma nova leitura
}
