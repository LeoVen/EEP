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
const int s0 = 1;
const int sensor1 = s0 + 1;
const int sensor2 = s0 + 2;
const int sensor3 = s0 + 3;
const int sensor4 = s0 + 4;
const int sensor5 = s0 + 5;
const int sensor6 = s0 + 6;
const int sensor7 = s0 + 7;
const int sensor8 = s0 + 8;

// Variaveis de configuracao
const int delayLedAmarelo = 1000; // 0.1 s

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
    pinMode(sensor5, INPUT);
    pinMode(sensor6, INPUT);
    pinMode(sensor7, INPUT);
    pinMode(sensor8, INPUT);

    digitalWrite(pinoLedVermelho, HIGH);
    digitalWrite(pinoLedAmarelo, LOW);
    digitalWrite(pinoLedVerde, LOW);
}

void loop()
{
    int s1 = digitalRead(sensor1);
    int s2 = digitalRead(sensor2);
    int s3 = digitalRead(sensor3);
    int s4 = digitalRead(sensor4);
    int s5 = digitalRead(sensor5);
    int s6 = digitalRead(sensor6);
    int s7 = digitalRead(sensor7);
    int s8 = digitalRead(sensor8);

    debug(s1, s2, s3, s4, s5, s6, s7, s8);

    if (condition(s1, s2, s3, s4, s5, s6, s7, s8))
    {
        // vermelho -> amarelo -> verde
        verde();

        while (condition(s1, s2, s3, s4, s5, s6, s7, s8))
        {
            delay(100);
            s1 = digitalRead(sensor1);
            s2 = digitalRead(sensor2);
            s3 = digitalRead(sensor3);
            s4 = digitalRead(sensor4);
            s5 = digitalRead(sensor5);
            s6 = digitalRead(sensor6);
            s7 = digitalRead(sensor7);
            s8 = digitalRead(sensor8);
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

int count(int s, int const array[])
{
    int total = 0;

    for (int i = 0; i < s; i++)
        if (array[i] == LOW)
            total++;

    return total;
}

bool condition(int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8)
{
    int ss[8] = {s1, s2, s3, s4, s5, s6, s7, s8}; // Todos os sensores
    int s_t[4] = {s1, s3, s5, s7};                // Sensores da travessa
    int s_a[4] = {s2, s4, s6, s8};                // Sensores da avenida

    // Estado padrão: não há nenhum sensor ligado ou todos estão ligados
    int t = count(8, ss);
    if (t == 0 || t == 8)
        return false;

    // Se se há mais sensores frontais (s1, s2, s3, s4) na travessa, verde
    // Se há menos, vermelho
    if (count(2, s_t) > count(2, s_a))
        return true;
    if (count(2, s_t) < count(2, s_a))
        return false;

    // Aqui sensores frontais estão em mesma quantidade
    // Desempate aquele que tiver mais sensores ligados no total
    return count(4, s_t) > count(4, s_a);
}

void debug(int s1, int s2, int s3, int s4, int s5, int s6, int s7, int s8)
{
    Serial.print(s1 == LOW ? "[1, " : "[0, ");
    Serial.print(s2 == LOW ? "1, " : "0, ");
    Serial.print(s3 == LOW ? "1, " : "0, ");
    Serial.print(s4 == LOW ? "1, " : "0, ");
    Serial.print(s5 == LOW ? "1, " : "0, ");
    Serial.print(s6 == LOW ? "1, " : "0, ");
    Serial.print(s7 == LOW ? "1, " : "0, ");
    Serial.print(s8 == LOW ? "1 ]\n" : "0 ]\n");
}
