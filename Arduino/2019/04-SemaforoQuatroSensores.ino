/**
 * Grupo 5
 *
 * Eduardo Vencovsky        201710281
 * Erick Domingos Modenez   201710299
 * Leonardo Vencovsky       201710276
 * Lucas Alberto Nascimento 201710282
 */

// Pinos

// Semaforos
const int pinoLedVerde = 12;
const int pinoLedAmarelo = 11;
const int pinoLedVermelho = 10;

// Sensores
const int sensor1 = 9;
const int sensor2 = 8;
const int sensor3 = 7;
const int sensor4 = 6;

// Variaveis de configuracao
const int delayLedAmarelo = 2000; // 2 s
const int delayLedVerde = 6000;   // 6s -> quanto tempo ligado

void setup()
{
    Serial.begin(9600);

    pinMode(pinoLedVerde, OUTPUT);
    pinMode(pinoLedAmarelo, OUTPUT);
    pinMode(pinoLedVermelho, OUTPUT);

    pinMode(sensor1, INPUT);
    pinMode(sensor2, INPUT);
    pinMode(sensor3, INPUT);
    pinMode(sensor4, INPUT);

    digitalWrite(pinoLedVermelho, HIGH);
}

void loop()
{
    int s1 = digitalRead(sensor1);
    int s2 = digitalRead(sensor2);
    int s3 = digitalRead(sensor3);
    int s4 = digitalRead(sensor4);

    if (((s1 == HIGH || s3 == HIGH) && (s2 == LOW && s4 == LOW)) ||
        ((s1 == HIGH && s3 == HIGH) && (s2 == HIGH || s3 == HIGH)))
    {

        // Vermelho -> amarelo -> verde

        // desliga vermelho
        digitalWrite(pinoLedVermelho, LOW);

        // amarelo
        digitalWrite(pinoLedAmarelo, HIGH);
        delay(delayLedAmarelo);
        digitalWrite(pinoLedAmarelo, LOW);

        // liga verde e espera
        digitalWrite(pinoLedVerde, HIGH);
        delay(delayLedVerde);

        // Volta ao vermelho
        digitalWrite(pinoLedVerde, LOW);
        digitalWrite(pinoLedVermelho, HIGH);
    }
}
