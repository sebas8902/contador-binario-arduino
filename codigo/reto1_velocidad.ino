const int BIT0 = 8;
const int BIT1 = 9;
const int BIT2 = 10;
const int BIT3 = 11;

const int BOTON_PIN = 7;

int contador = 0;
int estadoBotonAnterior = HIGH;

void setup()
{
  pinMode(BIT0, OUTPUT);
  pinMode(BIT1, OUTPUT);
  pinMode(BIT2, OUTPUT);
  pinMode(BIT3, OUTPUT);

  pinMode(BOTON_PIN, INPUT_PULLUP);

  actualizarLeds(contador);
}

void actualizarLeds(int numero)
{
  digitalWrite(BIT0, (numero & (1 << 0)) ? HIGH : LOW);
  digitalWrite(BIT1, (numero & (1 << 1)) ? HIGH : LOW);
  digitalWrite(BIT2, (numero & (1 << 2)) ? HIGH : LOW);
  digitalWrite(BIT3, (numero & (1 << 3)) ? HIGH : LOW);
}

void loop()
{
  int estadoBotonActual = digitalRead(BOTON_PIN);

  if (estadoBotonAnterior == HIGH && estadoBotonActual == LOW)
  {
    contador = (contador + 1) % 16;

    actualizarLeds(contador);

    delay(50);
  }

  estadoBotonAnterior = estadoBotonActual;
}
