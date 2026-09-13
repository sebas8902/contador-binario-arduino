# contador-binario-arduino
Diseñar, construir, programar y documentar un contador binario de 4 bits utilizando Arduino y LEDs, aplicando los conceptos trabajados en clase sobre salidas digitales, representación binaria, estructuras repetitivas, arreglos, operadores bit a bit y montaje básico de circuitos electrónicos.

# Parcial Práctico — Contador Binario de 4 Bits con Arduino UNO

## 1. Descripción del Proyecto
Este proyecto documenta la creación, desarrollo físico y simulación de un contador binario de 4 bits mediante una placa Arduino UNO. El sistema representa valores decimales del 0 al 15 mediante cuatro LEDs en formato binario, procesando el encendido/apagado de las salidas digitales utilizando operaciones a nivel de bits (bitwise).


## 2. Materiales Utilizados
* 1x Placa Arduino UNO R3
* 1x Protoboard
* 4x LEDs para conteo (1x Verde, 1x Rojo, 1x Azul, 1x Rojo)
* 1x LED adicional para indicador (Reto 5)
* 5x Resistencias limitadoras de 220 Ω
* 1x Pulsador (Reto 3)
* Cables de conexión Jumper


## 3. Explicación del Circuito Físico
* **Salidas del Contador:** Los ánodos de los LEDs están conectados a través de resistencias de 220 Ω a los pines digitales de salida:
  * **Pin 8 (`BIT0`):** LSB - Bit 0 ($2^0 = 1$)
  * **Pin 9 (`BIT1`):** Bit 1 ($2^1 = 2$)
  * **Pin 10 (`BIT2`):** Bit 2 ($2^2 = 4$)
  * **Pin 11 (`BIT3`):** MSB - Bit 3 ($2^3 = 8$)
* **Línea de Masa (GND):** Todos los cátodos de los LEDs comparten la línea negativa de la protoboard conectada directamente al pin **GND** de la placa Arduino.
* **Pulsador (Reto 3):** Conectado al **Pin 7** en configuración `INPUT_PULLUP`.
* **LED Indicador (Reto 5):** Conectado al **Pin 12** a través de una resistencia de 220 Ω.



## 4. Funcionamiento del Contador Binario

| Decimal | Binario | Pin 11 (MSB) | Pin 10 | Pin 9 | Pin 8 (LSB) |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | 0000 | OFF | OFF | OFF | OFF |
| 1 | 0001 | OFF | OFF | OFF | ON |
| 2 | 0010 | OFF | OFF | ON | OFF |
| 3 | 0011 | OFF | OFF | ON | ON |
| 4 | 0100 | OFF | ON | OFF | OFF |
| 5 | 0101 | OFF | ON | OFF | ON |
| 6 | 0110 | OFF | ON | ON | OFF |
| 7 | 0111 | OFF | ON | ON | ON |
| 8 | 1000 | ON | OFF | OFF | OFF |
| 9 | 1001 | ON | OFF | OFF | ON |
| 10 | 1010 | ON | OFF | ON | OFF |
| 11 | 1011 | ON | OFF | ON | ON |
| 12 | 1100 | ON | ON | OFF | OFF |
| 13 | 1101 | ON | ON | OFF | ON |
| 14 | 1110 | ON | ON | ON | OFF |
| 15 | 1111 | ON | ON | ON | ON |



## 5. Explicación del Código y Funciones

* **`setup()`**: Función de inicialización ejecutada una sola vez al arrancar la placa. Define los modos de los pines.
* **`loop()`**: Ciclo principal repetitivo que ejecuta la secuencia del contador.
* **`pinMode()`**: Configura los pines 8, 9, 10 y 11 como salidas (`OUTPUT`).
* **`digitalWrite()`**: Escribe un valor `HIGH` (5V) o `LOW` (0V) en el pin correspondiente.
* **`digitalRead()`**: Lee la entrada del pulsador (`HIGH` o `LOW`).
* **`delay()`**: Define el tiempo de pausa en milisegundos entre cambios de número.
### Explicación de Operadores Bitwise y Funciones Bit

Para controlar los LEDs individualmente sin escribir condicionales manuales para cada número (del 0 al 15), se analiza la representación binaria de la variable `numero` mediante dos enfoques:

#### 1. Operaciones Bitwise (`&` y `<<`)
Se evalúa la presencia de un `1` lógico en una posición específica utilizando una máscara binaria:

```cpp
digitalWrite(PIN, (numero & (1 << i)) ? HIGH : LOW); 
```
## 6. Desarrollo de los retos
### Reto 1 — Velocidad del contador
**¿Qué se solicitaba?**

Modificar el contador para que el tiempo entre cada número fuera de 500 ms.

**Modificación realizada**

Se creó la variable:
```cpp
const int waitDelay = 500;
```
Después se utilizó:

delay(waitDelay);

Esto evita escribir directamente delay(500) en diferentes partes del programa.

Resultado

El contador muestra cada número durante aproximadamente 500 ms antes de avanzar al siguiente.

Reto 2 — Contador descendente
¿Qué se solicitaba?

Modificar el contador para que realizara la secuencia:

15, 14, 13, 12 ... 3, 2, 1, 0
Modificación realizada

Se modificó el ciclo for para comenzar en 15 y disminuir:

for (int numero = 15; numero >= 0; numero--)
Resultado

Los LEDs representan los números desde 15 hasta 0 en orden descendente. Al terminar el ciclo, vuelve a comenzar desde 15.

Reto 3 — Control mediante botón
¿Qué se solicitaba?

Agregar un pulsador para que el contador avanzara solamente cuando el usuario presionara el botón.

Modificación realizada

Se agregó el botón al pin digital 7:

const int BOTON_PIN = 7;

Se configuró como entrada utilizando:

pinMode(BOTON_PIN, INPUT_PULLUP);

Luego se utiliza digitalRead() para conocer el estado del botón.

Cada vez que se detecta una pulsación, el contador aumenta:

contador = (contador + 1) % 16;
Resultado

El contador deja de avanzar automáticamente y cambia de número cada vez que se presiona el botón.

La secuencia es:

0
↓ botón
1
↓ botón
2
↓ botón
3
...
15
↓ botón
0
Reto 4 — Mostrar solamente números pares
¿Qué se solicitaba?

Modificar el contador para mostrar únicamente:

0, 2, 4, 6, 8, 10, 12, 14
Modificación realizada

Se modificó el ciclo para aumentar el número de dos en dos:

for (int numero = 0; numero <= 14; numero += 2)
Resultado

El contador solamente muestra números pares y los cuatro LEDs representan cada número en su correspondiente forma binaria.

Reto 5 — LED indicador
¿Qué se solicitaba?

Agregar un quinto LED que permaneciera apagado durante el conteo normal y se encendiera cuando el contador llegara a 15.

Modificación realizada

Se agregó el quinto LED en el pin 12:

const int LED_INDICADOR = 12;

El programa comprueba si el número es 15:

if (numero == 15)
{
    digitalWrite(LED_INDICADOR, HIGH);
}
else
{
    digitalWrite(LED_INDICADOR, LOW);
}
Resultado

El quinto LED permanece apagado durante los números del 0 al 14.

Cuando los cuatro LEDs principales representan:

15 = 1111

el quinto LED se enciende.

Al comenzar nuevamente el conteo, el LED indicador vuelve a apagarse.

8. Simulación en Tinkercad

Se realizaron simulaciones de los diferentes ejercicios utilizando Tinkercad Circuits.

Contador binario de 4 bits

Enlace: [PONER AQUÍ EL ENLACE DE TINKERCAD]

Reto 1 — Velocidad

Enlace: [PONER AQUÍ EL ENLACE DE TINKERCAD]

Reto 2 — Contador descendente

Enlace: [PONER AQUÍ EL ENLACE DE TINKERCAD]

Reto 3 — Botón

Enlace: [PONER AQUÍ EL ENLACE DE TINKERCAD]

Reto 4 — Números pares

Enlace: [PONER AQUÍ EL ENLACE DE TINKERCAD]

Reto 5 — LED indicador

Enlace: [PONER AQUÍ EL ENLACE DE TINKERCAD]

9. Evidencias del montaje físico

Se realizó el montaje físico del contador utilizando Arduino, protoboard, LEDs, resistencias y cables jumper.

Las fotografías permiten observar el montaje y el funcionamiento de los LEDs.

Las evidencias se encuentran organizadas en la carpeta:

evidencias/montaje_fisico/
10. Evidencias de las simulaciones

Las capturas de las simulaciones realizadas en Tinkercad se encuentran organizadas en:

evidencias/simulacion/

En ellas se puede observar el funcionamiento de los diferentes retos.

11. Video del funcionamiento

Se realizó un video donde se muestra el funcionamiento del circuito físico.

Video: [PEGAR AQUÍ EL ENLACE DEL VIDEO]

12. Conclusión

La realización de este proyecto permitió comprender cómo Arduino puede utilizar sus salidas digitales para representar información binaria mediante LEDs.

A través de los cuatro LEDs fue posible representar los valores del 0 al 15 utilizando los cuatro bits de un número binario. También se aplicaron ciclos for, variables, entradas y salidas digitales, el uso de un pulsador y operaciones bit a bit.

Los diferentes retos permitieron modificar el funcionamiento inicial del contador y comprobar cómo pequeños cambios en el programa pueden producir diferentes comportamientos en el circuito.

Finalmente, la simulación en Tinkercad y el montaje físico permitieron comprobar el funcionamiento del programa tanto de manera virtual como real.


Los diferentes retos permitieron modificar el funcionamiento inicial del contador y comprobar cómo pequeños cambios en el programa pueden producir diferentes comportamientos en el circuito.

Finalmente, la simulación en Tinkercad y el montaje físico permitieron comprobar el funcionamiento del programa tanto de manera virtual como real.
