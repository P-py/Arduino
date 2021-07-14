//Definindo variáveis
#define led_green_pedestrians 9
#define led_red_pedestrians 10
#define led_green_cars 11
#define led_yellow_cars 12
#define led_red_cars 13


void setup() {
    //Configurando os pinos dos LEDS para modo saída.
    pinMode(led_green_pedestrians, OUTPUT);
    pinMode(led_red_pedestrians, OUTPUT);
    pinMode(led_green_cars, OUTPUT);
    pinMode(led_yellow_cars, OUTPUT);
    pinMode(led_red_cars, OUTPUT);
}

void loop() {
    //Sinal para pedestres fechado - apenas LED vermelho.
    printf("Sinal para pedestres fechado.");
    digitalWrite(led_green_pedestrians, LOW);
    digitalWrite(led_red_pedestrians, HIGH);
    //Sinal para carros aberto - apenas LED verde.
    printf("Sinal para carros aberto.");
    digitalWrite(led_green_cars, HIGH);
    digitalWrite(led_yellow_cars, LOW);
    digitalWrite(led_red_cars, LOW);
    delay(3000);

    //Sinal para carros fechando - apenas LED amarelo.
    printf("Sinal para carros fechando.");
    digitalWrite(led_green_cars, LOW);
    digitalWrite(led_yellow_cars, HIGH);
    digitalWrite(led_red_cars, LOW);
    delay(2000);

    //Sinal para carros fechado - apenas LED vermelho.
    printf("Sinal para carros fechado.");
    digitalWrite(led_green_cars, LOW);
    digitalWrite(led_yellow_cars, LOW);
    digitalWrite(led_red_cars, HIGH);

    //Sinal para pedestres aberto - apenas LED verde.
    printf("Sinal para pedestres aberto.");
    digitalWrite(led_green_pedestrians, HIGH);
    digitalWrite(led_red_pedestrians, LOW);
    delay(3000);

    //Sinal para pedestres fechando - LED verde apagado, LED vermelho piscando.
    printf("Sinal para pedestres fechando.");
    digitalWrite(led_green_pedestrians, LOW);
    digitalWrite(led_red_pedestrians, HIGH);
    delay(250);
    digitalWrite(led_red_pedestrians, LOW);
    delay(250);
    digitalWrite(led_red_pedestrians, HIGH);
    delay(250);
    digitalWrite(led_red_pedestrians, LOW);
    delay(250);
    digitalWrite(led_red_pedestrians, HIGH);
    delay(250);
    digitalWrite(led_red_pedestrians, LOW);
    delay(250);
    digitalWrite(led_red_pedestrians, HIGH);
    delay(250);
    digitalWrite(led_red_pedestrians, LOW);
}
