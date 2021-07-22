// Variáveis de conexão
const int pinoA = 12;
const int pinoB = 9;
const int pinoC = 10;
const int pinoD = 11;

// Variáveis globais
char leitura_serial;

void setup() {
  // Configurando os pinos
  pinMode(pinoA, OUTPUT);
  pinMode(pinoB, OUTPUT);
  pinMode(pinoC, OUTPUT);
  pinMode(pinoD, OUTPUT);

  // Iniciando e configurando a serial
  Serial.begin(9600);
  Serial.println("Digite um número de 0 a 9");
}

void loop() {
  if (Serial.available() > 0) {
    leitura_serial = Serial.read();
    Serial.println(leitura_serial);
    if(leitura_serial == '0'){
          digitalWrite(pinoA, LOW);
          digitalWrite(pinoB, LOW);
          digitalWrite(pinoC, LOW);
          digitalWrite(pinoD, LOW);
    }
    if(leitura_serial == '1'){
        digitalWrite(pinoA, HIGH);
        digitalWrite(pinoB, LOW);
        digitalWrite(pinoC, LOW);
        digitalWrite(pinoD, LOW);
    }
      
    if(leitura_serial == '2'){
        digitalWrite(pinoA, LOW);
        digitalWrite(pinoB, HIGH);
        digitalWrite(pinoC, LOW);
        digitalWrite(pinoD, LOW);
    }
      
    if(leitura_serial == '3'){
        digitalWrite(pinoA, HIGH);
        digitalWrite(pinoB, HIGH);
        digitalWrite(pinoC, LOW);
        digitalWrite(pinoD, LOW);
    }
      
    if(leitura_serial == '4'){
        digitalWrite(pinoA, LOW);
        digitalWrite(pinoB, LOW);
        digitalWrite(pinoC, HIGH);
        digitalWrite(pinoD, LOW);
    }
      
    if(leitura_serial == '5'){
        digitalWrite(pinoA, HIGH);
        digitalWrite(pinoB, LOW);
        digitalWrite(pinoC, HIGH);
        digitalWrite(pinoD, LOW);
    }
      
    if(leitura_serial == '6'){
        digitalWrite(pinoA, LOW);
        digitalWrite(pinoB, HIGH);
        digitalWrite(pinoC, HIGH);
        digitalWrite(pinoD, LOW);
    }
      
    if(leitura_serial == '7'){
        digitalWrite(pinoA, HIGH);
        digitalWrite(pinoB, HIGH);
        digitalWrite(pinoC, HIGH);
        digitalWrite(pinoD, LOW);
    }
      
    if(leitura_serial == '8'){
        digitalWrite(pinoA, LOW);
        digitalWrite(pinoB, LOW);
        digitalWrite(pinoC, LOW);
        digitalWrite(pinoD, HIGH);
    }
      
    if(leitura_serial == '9'){
        digitalWrite(pinoA, HIGH);
        digitalWrite(pinoB, LOW);
        digitalWrite(pinoC, LOW);
        digitalWrite(pinoD, HIGH);
    }
  }
}
