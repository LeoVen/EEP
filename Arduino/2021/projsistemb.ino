#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "DHT.h"

// LDR
const int porta_LDR = A1;

// LM35
int pino_LM35 = A0;

// SRF04
const int pino_SRF04_TRIGGER = 3;
const int pino_SRF04_ECHO = 2;

// DHT11
const int DHTPIN = 4;
DHT dht(DHTPIN, DHT11, 6);

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD I2C address

void setup()
{
    pinMode(pino_SRF04_TRIGGER, OUTPUT);
    pinMode(pino_SRF04_ECHO, INPUT);

    Serial.begin(9600);

    lcd.begin(16, 2);
    lcd.clear();

    Serial.println("-------------------------------------------");
    Serial.println("Escola de Engenharia de Piracicaba - EEP");
    Serial.println("-------------------------------------------");
    Serial.println("");
    lcd_show("Escola de Eng.", "de Piracicaba", 2000);

    Serial.println("-------------------------------------------");
    Serial.println("Disciplina de Sistemas Embarcados");
    Serial.println("-------------------------------------------");
    Serial.println("");
    lcd_show("    Sistemas", "   Embarcados", 2000);

    Serial.println("-------------------------------------------");
    Serial.println("Projeto 01 - Estacao Meteorologica");
    Serial.println("-------------------------------------------");
    Serial.println("");
    lcd_show("PRJ01 - Estacao", "Meteorologica", 2000);

    Serial.println("-------------------------------------------");
    Serial.println("Componentes da Equipe");
    Serial.println("Leonardo Vencovsky 201710276");
    Serial.println("Vitor Facioli      201710292");
    Serial.println("-------------------------------------------");
    Serial.println("");
    lcd_show("Componentes:", "Jose Luis Zem", 2000);
}

void lcd_show(String top, String bottom, int seg)
{
    lcd.setCursor(0, 0);
    lcd.print(top);
    lcd.setCursor(0, 1);
    lcd.print(bottom);

    delay(seg);
    lcd.clear();
}

// --------------------------------------------------------------- LDR
void F_LDR()
{
    int valor_LDR = analogRead(porta_LDR);
    int luminosidade = map(valor_LDR, 0, 765, 0, 100);
    Serial.println("Sensor LDR");
    Serial.println("-------------------------------------------");
    Serial.println(String("Valor obtido: ") + valor_LDR);
    Serial.println(String("Valor calculado: ") + luminosidade);
    Serial.println("-------------------------------------------");
    Serial.println("");
    lcd_show("Sensor LDR", String("Obtido: ") + valor_LDR, 2000);
    lcd_show("Sensor LDR", String("Calculado: ") + luminosidade, 3000);
}

// --------------------------------------------------------------- LM35
void F_LM35()
{
    const int N_AMOSTRAS = 8;

    int temp_c = 0;
    int temp_f = 0;

    for (int i = 0; i < N_AMOSTRAS; i++)
    {
        temp_c += (5.0 * analogRead(pino_LM35) * 100.0) / 1024.0;
        delay(100);
    }

    temp_c = temp_c / N_AMOSTRAS;
    temp_f = (temp_c * 9) / 5 + 32;

    Serial.println("Sensor LM35");
    Serial.println("-------------------------------------------");
    Serial.println(String("Temp: ") + temp_c + String(" C"));
    Serial.println(String("Temp: ") + temp_f + String(" F"));
    Serial.println("-------------------------------------------");
    Serial.println("");
    lcd_show("Sensor LM35", String("Temp: ") + temp_c + String(" C"), 2000);
    lcd_show("Sensor LM35", String("Temp: ") + temp_f + String(" F"), 3000);
}

// --------------------------------------------------------------- SFR04
long read_SFR04()
{
    digitalWrite(pino_SRF04_TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(pino_SRF04_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(pino_SRF04_TRIGGER, LOW);

    return pulseIn(pino_SRF04_ECHO, HIGH);
}

void F_SFR04()
{
    int centimetros = 0.01723 * read_SFR04();
    int polegadas = (centimetros / 2.54);

    Serial.println("Sensor SRF04");
    Serial.println("-------------------------------------------");
    Serial.println(String("Distancia: ") + centimetros + String(" cm"));
    Serial.println(String("Distancia: ") + polegadas + String(" pol"));
    Serial.println("-------------------------------------------");
    Serial.println("");
    lcd_show("Sensor SRF04", String("Dist: ") + centimetros + String(" cm"), 2000);
    lcd_show("Sensor SRF04", String("Dist: ") + polegadas + String(" pol"), 3000);
}

// --------------------------------------------------------------- DHT11
void F_DHT11()
{
    float umidade_ar = dht.readHumidity();
    float temperatura_celsius = dht.readTemperature(false);
    float temperatura_fahrenheit = dht.readTemperature(true);
    float sensacao_termica = dht.computeHeatIndex(temperatura_celsius, umidade_ar, false);

    Serial.println("Sensor DHT11");
    Serial.println("-------------------------------------------");
    Serial.println(String("Temperatura: ") + temperatura_celsius + String(" C"));
    Serial.println(String("Temperatura: ") + temperatura_fahrenheit + String(" F"));
    Serial.println(String("Umididade: ") + umidade_ar + String(" %"));
    Serial.println(String("Sensacao Termica: ") + sensacao_termica + String(" C"));
    Serial.println("-------------------------------------------");
    Serial.println("");
    lcd_show("Sensor DHT11", String("Temp: ") + temperatura_celsius + String(" C"), 2000);
    lcd_show("Sensor DHT11", String("Temp: ") + temperatura_fahrenheit + String(" F"), 2000);
    lcd_show("Sensor DHT11", String("Umid: ") + umidade_ar + String(" %"), 2000);
    lcd_show("Sensor DHT11", String("Sens: ") + sensacao_termica + String(" C"), 3000);
}

void loop()
{
    Serial.println("-------------------------------------------");
    Serial.println("Recuperar dados dos sensores ...");
    Serial.println("-------------------------------------------");
    Serial.println("");

    lcd_show("Recuperar dados", "dos sensores", 2000);

    F_LDR();
    F_LM35();
    F_SFR04();
    F_DHT11();
}
