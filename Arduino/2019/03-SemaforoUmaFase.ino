/**
 * Grupo 5
 *
 * Eduardo Vencovsky        201710281
 * Erick Domingos Modenez   201710299
 * Leonardo Vencovsky       201710276
 * Lucas Alberto Nascimento 201710282
 */

/**
 *
 * Verde    :  LOW |  LOW | HIGH
 * Amarelo  :  LOW | HIGH |  LOW
 * Vermelho : HIGH |  LOW |  LOW
 * ------------------------------
 *                 |   *  |  **
 * *   delay
 * **  sem delay (obstaculo)
 */

// Pinos
const int pinoLedVerde = 12;
const int pinoLedAmarelo = 10;
const int pinoLedVermelho = 9;
const int pinoSensor = 7;

// Variaveis de configuracao
const int delayLedAmarelo = 2000; // 2 s

// Controladores
bool ligadoVermelho = true;
bool ligadoVerde = false;

void setup()
{
    Serial.begin(9600);

    pinMode(pinoLedVermelho, OUTPUT);
    pinMode(pinoLedAmarelo, OUTPUT);
    pinMode(pinoLedVerde, OUTPUT);

    digitalWrite(pinoLedVermelho, HIGH);
}

void loop()
{
    /**
     *    1. Vermelho ligado enquanto sensor LOW
     *    2. Se sensor HIGH (objeto ativou o sensor)
     *        ? 2.1 Delay led amarelo
     *        2.2 Led troca para verde
     *    3. Se sensor LOW  (objeto deixou o sensor)
     *        3.1 Delay led amarelo
     *        3.2 Led troca para vermelho
     *    4. Loop 1.
     */

    int sensor = digitalRead(pinoSensor);

    if (sensor == HIGH && ligadoVermelho)
    {
        digitalWrite(pinoLedVermelho, LOW);

        // pulsoAmarelo();

        digitalWrite(pinoLedVerde, HIGH);

        ligadoVermelho = false;
        ligadoVerde = true;

        Serial.write("VERDE");
    }
    else if (sensor == LOW && ligadoVerde)
    {
        digitalWrite(pinoLedVerde, LOW);

        pulsoAmarelo();

        digitalWrite(pinoLedVermelho, HIGH);

        ligadoVermelho = true;
        ligadoVerde = false;

        Serial.write("VERMELHO");
    }
}

void pulsoAmarelo()
{
    digitalWrite(pinoLedAramelo, HIGH);

    Serial.write("AMARELO");

    delay(delayLedAmarelo);

    digitalWrite(pinoLedAmarelo, LOW);
}
