int shortTime = 500;
int longTime = 200;
int breakTime = 1000;
int finishTime = 2000;

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
    increasingBlink(6);
}

void increasingBlink(int secondLimit)
{
    for (int i = 1; i <= secondLimit; i++)
    {
        dynamicSignal(i * 1000, breakTime);
    }
    crazyBlink();
}

void crazyBlink()
{
    for (int i = 0; i < 10; i++)
    {
        dynamicSignal(100, 100);
    }
}

void sos()
{
    shortSignal(); //
    shortSignal(); // S
    shortSignal(); //

    longSignal(); //
    longSignal(); // O
    longSignal(); //

    shortSignal(); //
    shortSignal(); // S
    shortSignal(); //

    delay(finishTime);
}

void dynamicSignal(int onTime, int offTime)
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(onTime);
    digitalWrite(LED_BUILTIN, LOW);
    delay(offTime);
}

void shortSignal()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(shortTime);
    digitalWrite(LED_BUILTIN, LOW);
    delay(breakTime);
}

void longSignal()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(longTime);
    digitalWrite(LED_BUILTIN, LOW);
    delay(breakTime);
}
