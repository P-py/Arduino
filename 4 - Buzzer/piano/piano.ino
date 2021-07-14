//Variáveis

const int pinoBuzzer = 10; //Pino digital correspondente à conexão com o Buzzer.

//Frequências de cada nota musical.
const int c = 261; //Dó
const int d = 293; //Ré
const int e = 329; //Mi
const int f = 349; //Fá
const int g = 391; //Sol
const int a = 440; //Lá
const int b = 493; //Si 

void setup() {
  pinMode(pinoBuzzer, OUTPUT); //Configurando o pino digital do Buzzer como saída de dados.
  Serial.begin(9600);
}

void loop() {
  delay(3000); //Espera 3 segundos
  
  //Toca a nota Dó
  Serial.write("Dó \n");
  tone(pinoBuzzer, c);
  delay(1000);

  //Nota Ré
  Serial.write("Ré \n");
  tone(pinoBuzzer, d);
  delay(1000);

  //Nota Mi
  Serial.write("Mi \n");
  tone(pinoBuzzer, e);
  delay(1000);

  //Nota Fá
  Serial.write("Fá \n");
  tone(pinoBuzzer, f);
  delay(1000);

  //Nota Sol
  Serial.write("Sol \n");
  tone(pinoBuzzer, g);
  delay(1000);
  
  //Nota Lá
  Serial.write("Lá \n");
  tone(pinoBuzzer, a);
  delay(1000);
  
  //Nota Si
  Serial.write("Si \n");
  tone(pinoBuzzer, b);
  delay(1000);
  
  //Desliga o Buzzer por 5 segundos.
  noTone(pinoBuzzer);
  delay(5000);
}
