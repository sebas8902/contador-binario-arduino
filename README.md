# contador-binario-arduino
Diseñar, construir, programar y documentar un contador binario de 4 bits utilizando Arduino y LEDs, aplicando los conceptos trabajados en clase sobre salidas digitales, representación binaria, estructuras repetitivas, arreglos, operadores bit a bit y montaje básico de circuitos electrónicos.

# Parcial Práctico — Contador Binario de 4 Bits con Arduino UNO

## 1. Descripción del Proyecto
Este proyecto documenta la creación, desarrollo físico y simulación de un contador binario de 4 bits mediante una placa Arduino UNO. El sistema representa valores decimales del 0 al 15 mediante cuatro LEDs en formato binario, procesando el encendido/apagado de las salidas digitales utilizando operaciones a nivel de bits (bitwise).

---

## 2. Materiales Utilizados
* 1x Placa Arduino UNO R3
* 1x Protoboard
* 4x LEDs para conteo (1x Verde, 1x Rojo, 1x Azul, 1x Rojo)
* 1x LED adicional para indicador (Reto 5)
* 5x Resistencias limitadoras de 220 Ω
* 1x Pulsador (Reto 3)
* Cables de conexión Jumper

---

## 3. Explicación del Circuito Físico
* **Salidas del Contador:** Los ánodos de los LEDs están conectados a través de resistencias de 220 Ω a los pines digitales de salida:
  * **Pin 8 (`BIT0`):** LSB - Bit 0 ($2^0 = 1$)
  * **Pin 9 (`BIT1`):** Bit 1 ($2^1 = 2$)
  * **Pin 10 (`BIT2`):** Bit 2 ($2^2 = 4$)
  * **Pin 11 (`BIT3`):** MSB - Bit 3 ($2^3 = 8$)
* **Línea de Masa (GND):** Todos los cátodos de los LEDs comparten la línea negativa de la protoboard conectada directamente al pin **GND** de la placa Arduino.
* **Pulsador (Reto 3):** Conectado al **Pin 7** en configuración `INPUT_PULLUP`.
* **LED Indicador (Reto 5):** Conectado al **Pin 12** a través de una resistencia de 220 Ω.

---

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

---

## 5. Explicación del Código y Funciones

* **`setup()`**: Función de inicialización ejecutada una sola vez al arrancar la placa. Define los modos de los pines.
* **`loop()`**: Ciclo principal repetitivo que ejecuta la secuencia del contador.
* **`pinMode()`**: Configura los pines 8, 9, 10 y 11 como salidas (`OUTPUT`).
* **`digitalWrite()`**: Escribe un valor `HIGH` (5V) o `LOW` (0V) en el pin correspondiente.
* **`digitalRead()`**: Lee la entrada del pulsador (`HIGH` o `LOW`).
* **`delay()`**: Define el tiempo de pausa en milisegundos entre cambios de número.

### Explicación de Operadores Bitwise
Para evaluar cada bit de la variable `numero`, se aplican operaciones bit a bit:
```cpp
numero & (1 << i)
