
const int BIT0 = 8;
const int BIT1 = 9;
const int BIT2 = 10;
const int BIT3 = 11;

const int waitDelay = 500;

void setup()
{
  pinMode(BIT0, OUTPUT);
  pinMode(BIT1, OUTPUT);
  pinMode(BIT2, OUTPUT);
  pinMode(BIT3, OUTPUT);
}

void loop()
{
  for (int numero = 0; numero <= 15; numero++)
  {
    digitalWrite(BIT0, (numero & (1 << 0)) ? HIGH : LOW);
    digitalWrite(BIT1, (numero & (1 << 1)) ? HIGH : LOW);
    digitalWrite(BIT2, (numero & (1 << 2)) ? HIGH : LOW);
    digitalWrite(BIT3, (numero & (1 << 3)) ? HIGH : LOW);

    delay(waitDelay);
  }
}
