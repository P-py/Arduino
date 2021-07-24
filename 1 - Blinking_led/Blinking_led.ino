// Código escrito por Pedro Salviano Santos (@P-py) - MIT License //
// Meu site: P-py.github.io

#define led1 13

void setup() {
  pinMode(led1, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  delay(500);
}
