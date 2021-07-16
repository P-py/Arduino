//Variáveis de conexão
const int pinoPotenciometro = A0; //Pino analógico onde está o potenciômetro

//Variáveis globais
int leitura = 0; //Armazena o valor lido pelo ADC
float tensao = 0.0; //Armazena a tensão

void setup() {
  //Iniciando a Serial
  Serial.begin(9600);
  pinMode(pinoPotenciometro, INPUT); //Configurando o tipo de dado do potenciometro
}

void loop() {
  leitura = analogRead(pinoPotenciometro); //Coletando o valor analógico do potenciometro
  tensao = leitura*5 / 1024.0; //Convertendo o valor em tensão elétrica

  //Plottando os valores.
  Serial.print(leitura);
  Serial.print(" "); //Utilizado pra separar a exibição das variáveis;
  Serial.print(tensao*10);
  Serial.print(" ");
  Serial.print(tensao*50);
  Serial.print(" ");
  Serial.println(tensao*100);
  
  delay(100); //Espera 100ms para uma nova coleta de dados
}
