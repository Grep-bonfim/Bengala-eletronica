//direita tem dois big fio
//o da esquerda é o sem fita
// e o do meio é o com fita

const int trigPin = 4;
const int echoPin = A5;
const int motorPin = 10;

const int distanciaLimite = 30; // em centímetros

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);

  digitalWrite(motorPin, LOW); // Motor desligado inicialmente

  Serial.begin(9600); // Para monitorar a distância no Serial Monitor
}

long medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracao = pulseIn(echoPin, HIGH);
  long distancia = duracao * 0.034 / 2;

  return distancia;
}

void loop() {
  long distancia = medirDistancia();

  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

  digitalWrite(motorPin, HIGH);
  delay(5000);
  digitalWrite(motorPin, LOW);
  
  //if (distancia > 0 && distancia <= distanciaLimite) {
    //digitalWrite(motorPin, HIGH); // Liga o motor se objeto estiver próximo
  //} else {
    //digitalWrite(motorPin, LOW);  // Desliga o motor se estiver longe
  //}

  delay(200); // Espera um pouco antes da próxima leitura
}
