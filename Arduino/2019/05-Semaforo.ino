/**
 * Grupo 5
 *
 * Eduardo Vencovsky        201710281
 * Erick Domingos Modenez   201710299
 * Leonardo Vencovsky       201710276
 * Lucas Alberto Nascimento 201710282
 */

// Pinos

// Semaforo
const int pinoLedVerde = 13;
const int pinoLedAmarelo = 12;
const int pinoLedVermelho = 11;

// Sensores
const int s1 = 1;
const int s2 = 2;
const int s3 = 3;
const int s4 = 4;

// Variaveis de configuracao
const int delayLedAmarelo = 1000; // 0.1 s

void setup()
{
    Serial.begin(9600);

    pinMode(pinoLedVerde, OUTPUT);
    pinMode(pinoLedAmarelo, OUTPUT);
    pinMode(pinoLedVermelho, OUTPUT);

    pinMode(s1, INPUT);
    pinMode(s2, INPUT);
    pinMode(s3, INPUT);
    pinMode(s4, INPUT);

    digitalWrite(pinoLedVermelho, HIGH);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVerde, LOW);
}

void loop()
{
    int sinal1 = digitalRead(s1);
    int sinal2 = digitalRead(s2);
    int sinal3 = digitalRead(s3);
    int sinal4 = digitalRead(s4);

    Serial.print(sinal1 == LOW ? "[1, " : "[0, ");
    Serial.print(sinal2 == LOW ? "1, " : "0, ");
    Serial.print(sinal3 == LOW ? "1, " : "0, ");
    Serial.print(sinal4 == LOW ? "1 ]\n" : "0 ]\n");

    if (condition(sinal1, sinal2, sinal3, sinal4))
    {
        // vermelho -> amarelo -> verde
        verde();

        while (condition(sinal1, sinal2, sinal3, sinal4))
        {
            delay(100);
            sinal1 = digitalRead(s1);
            sinal2 = digitalRead(s2);
            sinal3 = digitalRead(s3);
            sinal4 = digitalRead(s4);
        }

        // vermelho -> amarelo -> verde
        vermelho();
    }
}

void pulsoAmarelo()
{
    Serial.write("Amarelo -> ");
    digitalWrite(pinoLedAmarelo, HIGH);

    delay(delayLedAmarelo);

    digitalWrite(pinoLedAmarelo, LOW);
}

void vermelho()
{
    Serial.write("Verde -> ");
    // desliga verde
    digitalWrite(pinoLedVerde, LOW);

    // amarelo
    pulsoAmarelo();

    // liga vermelho
    digitalWrite(pinoLedVermelho, HIGH);

    Serial.write("Vermelho\n");
}

void verde()
{
    Serial.write("Vermelho -> ");
    // desliga vermelho
    digitalWrite(pinoLedVermelho, LOW);

    // amarelo
    pulsoAmarelo();

    // liga verde
    digitalWrite(pinoLedVerde, HIGH);

    Serial.write("Verde\n");
}

bool condition(int sinal1, int sinal2, int sinal3, int sinal4)
{
    return (sinal1 == LOW || sinal3 == LOW) && (sinal2 == HIGH && sinal4 == HIGH);
}
