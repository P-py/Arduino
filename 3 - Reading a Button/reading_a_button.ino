//Definindo variáveis

void setup() {
    pinMode(9, INPUT); //Configura o pino digital 9 (Botão) como entrada de dados.
    pinMode(12, OUTPUT); //Configura o pino digital 12 (LED) como saída de dados.
}
void loop() {
    //Condicional - Lê a entrada digital do botão;
    //Caso o botão esteja pressionado -> Saída digital 12 se torna HIGH;
    //Caso o botão não esteja pressionado (LOW) -> Saída digital 12 se torna LOW;
    if (digitalRead(9) == HIGH) {
        digitalWrite(12, HIGH);
    }
    else {
        digitalWrite(12, LOW);
    }
}