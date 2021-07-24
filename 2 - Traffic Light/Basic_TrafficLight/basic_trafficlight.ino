// Código escrito por Pedro Salviano Santos (@p-py) - MIT License //
// Meu site: P-py.github.io

//Definindo as variáveis.
#define led_green 11
#define led_yellow 12
#define led_red 13

void setup() {
  //Configurando os pinos dos LEDS como OUTPUT(Saída).
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);
}

void loop() {
  //Sinal aberto: apenas LED verde.
  digitalWrite(led_green, HIGH);
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_red, LOW);
  delay(3000);
  
  //Sinal fechado: apenas LED amarelo.
  digitalWrite(led_green, LOW);
  digitalWrite(led_yellow, HIGH);
  digitalWrite(led_red, LOW);
  delay(1000);

  //Sinal fechado - continuidade: apenas LED vermelho.
  digitalWrite(led_green, LOW);
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_red, HIGH);
  delay(5000);
}
