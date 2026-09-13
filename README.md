# Parcial Práctico — Contador Binario de 4 Bits con Arduino UNO

## 1. Descripción del Proyecto

Este proyecto documenta el diseño, la simulación y la implementación física de un contador binario de 4 bits en Arduino UNO. El sistema representa números decimales del 0 al 15 mediante cuatro LEDs (del bit menos significativo al más significativo) utilizando operadores bit a bit (bitwise) y funciones de manipulación de bits para encender o apagar las salidas digitales.



[Ver Contador de 4 Bits (Proyecto Base)](./Contador_4_bits/)

[Ver Resolución de Retos](./Retos/)

[Ver Código Fuente](./codigo/)

## 10. Conclusión

La realización de este proyecto permitió comprender cómo la placa Arduino UNO utiliza sus salidas digitales para representar información binaria mediante LEDs.

A través de los cuatro LEDs fue posible representar los valores del 0 al 15 correspondientes a los cuatro bits de un número binario. Se aplicaron ciclos `for`, variables, entradas lógicas mediante `INPUT_PULLUP`, lectura de pulsadores y manipulación de bits con operadores bitwise y funciones como `bitRead()`.

Los retos permitieron iterar sobre el programa base y comprobar cómo pequeñas modificaciones en el código producen diferentes comportamientos físicos en el circuito. Finalmente, la simulación virtual en Tinkercad y el montaje en protoboard validaron la correcta ejecución teórica y práctica del proyecto.
