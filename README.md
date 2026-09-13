# Parcial Práctico — Contador Binario de 4 Bits con Arduino UNO

## 1. Descripción del Proyecto

Este proyecto documenta el diseño, la simulación y la implementación física de un contador binario de 4 bits en Arduino UNO. El sistema representa números decimales del 0 al 15 mediante cuatro LEDs (del bit menos significativo al más significativo) utilizando operadores bit a bit (bitwise) y funciones de manipulación de bits para encender o apagar las salidas digitales.

---

## 2. Materiales Utilizados

* 1x Placa Arduino UNO R3
* 1x Protoboard
* 4x LEDs para los bits del contador (Bit 0 a Bit 3)
* 1x LED indicador (Reto 5)
* 5x Resistencias limitadoras de 220 Ω
* 1x Pulsador / Botón (Reto 3)
* Cables Jumper

---

## 3. Explicación del Circuito

* **Salidas digitales de bits:** Los ánodos de los LEDs están conectados mediante resistencias de 220 Ω a los pines digitales:
* **Pin 8 (`BIT0`):** Bit 0 / LSB ($2^0 = 1$)
* **Pin 9 (`BIT1`):** Bit 1 ($2^1 = 2$)
* **Pin 10 (`BIT2`):** Bit 2 ($2^2 = 4$)
* **Pin 11 (`BIT3`):** Bit 3 / MSB ($2^3 = 8$)


* **Línea de Tierra (GND):** Todos los cátodos de los LEDs van a la línea negativa de la protoboard, conectada a un pin **GND** del Arduino.
* **Pulsador (`BOTON_PIN`):** Conectado al **Pin 7** en modo `INPUT_PULLUP`.
* **LED Indicador (`LED_INDICADOR`):** Conectado al **Pin 12** con su respectiva resistencia a tierra.

---

## 4. Funcionamiento del Contador Binario

| Decimal | Binario | Pin 11 (BIT3) | Pin 10 (BIT2) | Pin 9 (BIT1) | Pin 8 (BIT0) |
| --- | --- | --- | --- | --- | --- |
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

---

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

`digitalWrite(PIN, (numero & (1 << i)) ? HIGH : LOW);`

* **Desplazamiento a la izquierda (`1 << i`):** Toma el valor binario `0001` y lo desplaza $i$ posiciones a la izquierda.
* Para el bit 0 ($i=0$): `1 << 0` genera la máscara `0001` ($1$).
* Para el bit 1 ($i=1$): `1 << 1` genera la máscara `0010` ($2$).
* Para el bit 2 ($i=2$): `1 << 2` genera la máscara `0100` ($4$).
* Para el bit 3 ($i=3$): `1 << 3` genera la máscara `1000` ($8$).


* **Operador AND bitwise (`&`):** Realiza una comparación lógica AND bit a bit entre la variable `numero` y la máscara generada. Si el bit evaluado en el número contiene un `1`, el resultado completo es distinto de cero (`HIGH`). Si contiene un `0`, la operación devuelve cero (`LOW`).

#### 2. Uso de la función `bitRead()`

De forma equivalente, la función propia del núcleo de Arduino `bitRead(numero, i)` lee directamente el estado del bit en el índice $i$ (donde $0$ representa el bit menos significativo / LSB). Retorna un valor numérico directo `1` o `0`, el cual es interpretado como `HIGH` o `LOW` por la función `digitalWrite()`.

`digitalWrite(BIT0, bitRead(numero, 0));`

---

## 6. Desarrollo de los Retos

### Reto 1 — Velocidad del Contador

* **¿Qué se solicitaba?**
Modificar el contador para que el tiempo entre cada número fuera de 500 ms.


* **Modificación realizada:**
Se creó la variable `const int waitDelay = 500;`. Después se utilizó `delay(waitDelay);`. Esto evita escribir directamente `delay(500)` en diferentes partes del programa.


* **Resultado:**
El contador muestra cada número durante aproximadamente 500 ms antes de avanzar al siguiente.

---

### Reto 2 — Contador Descendente

* **¿Qué se solicitaba?**
Modificar el contador para que realizara la secuencia descendente: `15, 14, 13, 12 ... 3, 2, 1, 0`.


* **Modificación realizada:**
Se modificó el ciclo `for` para comenzar en 15 y disminuir: `for (int numero = 15; numero >= 0; numero--)`.


* **Resultado:**
Los LEDs representan los números desde 15 hasta 0 en orden descendente. Al terminar el ciclo, vuelve a comenzar desde 15.

---

### Reto 3 — Control mediante Botón

* **¿Qué se solicitaba?**
Agregar un pulsador para que el contador avanzara solamente cuando el usuario presionara el botón.


* **Modificación realizada:**
Se agregó el botón al pin digital 7 (`const int BOTON_PIN = 7;`) y se configuró como entrada utilizando `pinMode(BOTON_PIN, INPUT_PULLUP);`. Luego se utiliza `digitalRead()` para conocer el estado del botón y cada vez que se detecta una pulsación el contador aumenta: `contador = (contador + 1) % 16;`.


* **Resultado:**
El contador deja de avanzar automáticamente y cambia de número cada vez que se presiona el botón.
Secuencia: `0` $\rightarrow$ `1` $\rightarrow$ `2` $\rightarrow$ ... $\rightarrow$ `15` $\rightarrow$ `0`.

---

### Reto 4 — Mostrar Solamente Números Pares

* **¿Qué se solicitaba?**
Modificar el contador para mostrar únicamente: `0, 2, 4, 6, 8, 10, 12, 14`.


* **Modificación realizada:**
Se modificó el ciclo para aumentar el número de dos en dos: `for (int numero = 0; numero <= 14; numero += 2)`.


* **Resultado:**
El contador solamente muestra números pares y los cuatro LEDs representan cada número en su correspondiente forma binaria.

---

### Reto 5 — LED Indicador

* **¿Qué se solicitaba?**
Agregar un quinto LED que permaneciera apagado durante el conteo normal y se encendiera cuando el contador llegara a 15.


* **Modificación realizada:**
Se agregó el quinto LED en el pin 12 (`const int LED_INDICADOR = 12;`) y el programa comprueba si el número es 15 (`if (numero == 15) { digitalWrite(LED_INDICADOR, HIGH); } else { digitalWrite(LED_INDICADOR, LOW); }`).


* **Resultado:**
El quinto LED permanece apagado durante los números del 0 al 14. Cuando los cuatro LEDs principales representan `15` (`1111`), el quinto LED se enciende. Al reiniciar el conteo, vuelve a apagarse.



---

## 7. Simulación en Tinkercad

Se realizaron simulaciones de los diferentes ejercicios utilizando Tinkercad Circuits:

* **Contador binario de 4 bits:** [PONER AQUÍ EL ENLACE DE TINKERCAD]
* **Reto 1 — Velocidad:** [PONER AQUÍ EL ENLACE DE TINKERCAD]
* **Reto 2 — Contador descendente:** [PONER AQUÍ EL ENLACE DE TINKERCAD]
* **Reto 3 — Botón:** [PONER AQUÍ EL ENLACE DE TINKERCAD]
* **Reto 4 — Números pares:** [PONER AQUÍ EL ENLACE DE TINKERCAD]
* **Reto 5 — LED indicador:** [PONER AQUÍ EL ENLACE DE TINKERCAD]

---

## 8. Evidencias del Montaje Físico y Simulaciones

* **Montaje Físico:** Se realizó el montaje utilizando Arduino UNO, protoboard, LEDs, resistencias de 220 Ω y cables jumper. Las evidencias fotográficas se encuentran organizadas en la carpeta `evidencias/montaje_fisico/`.
* **Simulaciones:** Las capturas de pantalla de los circuitos funcionando en Tinkercad se ubican en la carpeta `evidencias/simulacion/`.

---

## 9. Video del Funcionamiento

Demostración en video del circuito físico en funcionamiento:

* **Enlace del Video:** [PEGAR AQUÍ EL ENLACE DEL VIDEO]

---

## 10. Conclusión

La realización de este proyecto permitió comprender cómo la placa Arduino UNO utiliza sus salidas digitales para representar información binaria mediante LEDs.

A través de los cuatro LEDs fue posible representar los valores del 0 al 15 correspondientes a los cuatro bits de un número binario. Se aplicaron ciclos `for`, variables, entradas lógicas mediante `INPUT_PULLUP`, lectura de pulsadores y manipulación de bits con operadores bitwise y funciones como `bitRead()`.

Los retos permitieron iterar sobre el programa base y comprobar cómo pequeñas modificaciones en el código producen diferentes comportamientos físicos en el circuito. Finalmente, la simulación virtual en Tinkercad y el montaje en protoboard validaron la correcta ejecución teórica y práctica del proyecto.
