# Parcial Práctico — Contador Binario de 4 Bits con Arduino UNO

Este repositorio contiene el desarrollo del parcial práctico sobre la implementación de un **Contador Binario de 4 Bits** utilizando una placa Arduino UNO. Se incluye el proyecto base junto con la resolución de 5 retos de programación e implementación en hardware.


## 📁 Navegación Directa del Repositorio

Para revisar los detalles, la documentación técnica y las evidencias multimedia, haz clic en los siguientes enlaces:

* **[Contador de 4 Bits (Proyecto Base)](./Contador_4_bits/)**    
Explicación completa del circuito principal, tabla de verdad, lista de materiales, capturas de Tinkercad, fotos del montaje físico y enlace al video demostrativo.

* **[Retos del Parcial (Retos 1 al 5)](./Retos/)**    
Documentación detallada de cada reto (velocidad, secuencia descendente, pulsador, números pares y LED indicador) junto con sus evidencias de simulación.

* **[Código Fuente (.ino)](./codigo/)**    
Archivos de código fuente en C++ para Arduino listos para compilar y cargar.



## Resumen General del Proyecto

### Componentes Utilizados

* 1x Placa Arduino UNO R3
* 1x Protoboard
* 4x LEDs para las salidas digitales (Bit 0 a Bit 3)
* 1x LED indicador adicional (Reto 5)
* 5x Resistencias limitadoras de 220 Ω
* 1x Pulsador / Botón (Reto 3)
* Cables Jumper

### Configuración de Pines

| Componente | Pin Arduino | Función / Descripción |
| --- | --- | --- |
| **Bit 0 (LSB)** | Pin 8 | Salida digital bit menos significativo ($2^0$) |
| **Bit 1** | Pin 9 | Salida digital bit 1 ($2^1$) |
| **Bit 2** | Pin 10 | Salida digital bit 2 ($2^2$) |
| **Bit 3 (MSB)** | Pin 11 | Salida digital bit más significativo ($2^3$) |
| **Pulsador** | Pin 7 | Entrada digital (`INPUT_PULLUP`) |
| **LED Indicador** | Pin 12 | Salida digital (Indicador de valor 15) |


##  Autores

* **Estudiante:** Sebastian DeLuque Garcia, Alberto Fandino Lopez
* **Asignatura:** Fundamentos de Mecatrónica / Sistemas
* **Institución:** Corporación Universitaria Americana


## Conclusión

La realización de este proyecto permitió comprender cómo la placa Arduino UNO utiliza sus salidas digitales para representar información binaria mediante LEDs.

A través de los cuatro LEDs fue posible representar los valores del 0 al 15 correspondientes a los cuatro bits de un número binario. Se aplicaron ciclos `for`, variables, entradas lógicas mediante `INPUT_PULLUP`, lectura de pulsadores y manipulación de bits con operadores bitwise y funciones como `bitRead()`.

Los retos permitieron iterar sobre el programa base y comprobar cómo pequeñas modificaciones en el código producen diferentes comportamientos físicos en el circuito. Finalmente, la simulación virtual en Tinkercad y el montaje en protoboard validaron la correcta ejecución teórica y práctica del proyecto.
