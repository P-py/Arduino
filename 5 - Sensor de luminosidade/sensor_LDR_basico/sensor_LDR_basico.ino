//Variáveis

const int pinoLDR = A0; //Pino Analógico (por isso o "A" antes) onde o sensor LDR está conectado.
int leitura = 0; //Variável para armazenar o valor lido pelo ADC
float tensao = 0.0; //Variável para armazenar a tensão

void setup() {
  Serial.begin(9600); //Inicia a Serial
  //9600bps
  pinMode(pinoLDR, INPUT); //Configura o pino A0 como entrada de dados
}

void loop() {
  //Lê o valor de tensão no pino do LDR
  leitura = analogRead(pinoLDR);

  //Imprime o valor lido pelo arduino (0 a 1023)
  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print("\t"); //Tabulação

  //Converte e imprime o valor em tensão elétrica
  tensao = leitura *5.0 /1024.0;
  Serial.print("Tensão: ");
  Serial.print(tensao);
  Serial.print("V \n");

  delay(1000); //Espera 1seg para uma nova leitura
}
