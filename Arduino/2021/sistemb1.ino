/*
   Código demonstrativo para a aula de Sistemas Embarcados,
   Curso de Ciência da Computação,
   EEP.
   Leonardo Vencovsky - 201710276
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void menu()
{
    Serial.println("Digite a mensagem: ");
}

void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.clear();
    menu();
}

void loop()
{
    lcd.setCursor(0, 0);
    lcd.print("MENSAGEM:");

    if (Serial.available())
    {
        String texto = Serial.readString();
        lcd.setCursor(0, 1);
        lcd.print(texto);

        delay(3000);
    }

    delay(1000);
    lcd.clear();
}