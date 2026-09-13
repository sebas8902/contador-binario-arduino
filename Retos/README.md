## 1. Desarrollo de los Retos

### Reto 1 — Velocidad del Contador

* **¿Qué se solicitaba?**
Modificar el contador para que el tiempo entre cada número fuera de 500 ms.


* **Modificación realizada:**
Se creó la variable `const int waitDelay = 500;`. Después se utilizó `delay(waitDelay);`. Esto evita escribir directamente `delay(500)` en diferentes partes del programa.


* **Resultado:**
El contador muestra cada número durante aproximadamente 500 ms antes de avanzar al siguiente.




### Reto 2 — Contador Descendente

* **¿Qué se solicitaba?**
Modificar el contador para que realizara la secuencia descendente: `15, 14, 13, 12 ... 3, 2, 1, 0`.


* **Modificación realizada:**
Se modificó el ciclo `for` para comenzar en 15 y disminuir: `for (int numero = 15; numero >= 0; numero--)`.


* **Resultado:**
Los LEDs representan los números desde 15 hasta 0 en orden descendente. Al terminar el ciclo, vuelve a comenzar desde 15.




### Reto 3 — Control mediante Botón

* **¿Qué se solicitaba?**
Agregar un pulsador para que el contador avanzara solamente cuando el usuario presionara el botón.


* **Modificación realizada:**
Se agregó el botón al pin digital 7 (`const int BOTON_PIN = 7;`) y se configuró como entrada utilizando `pinMode(BOTON_PIN, INPUT_PULLUP);`. Luego se utiliza `digitalRead()` para conocer el estado del botón y cada vez que se detecta una pulsación el contador aumenta: `contador = (contador + 1) % 16;`.


* **Resultado:**
El contador deja de avanzar automáticamente y cambia de número cada vez que se presiona el botón.
Secuencia: `0` $\rightarrow$ `1` $\rightarrow$ `2` $\rightarrow$ ... $\rightarrow$ `15` $\rightarrow$ `0`.




### Reto 4 — Mostrar Solamente Números Pares

* **¿Qué se solicitaba?**
Modificar el contador para mostrar únicamente: `0, 2, 4, 6, 8, 10, 12, 14`.


* **Modificación realizada:**
Se modificó el ciclo para aumentar el número de dos en dos: `for (int numero = 0; numero <= 14; numero += 2)`.


* **Resultado:**
El contador solamente muestra números pares y los cuatro LEDs representan cada número en su correspondiente forma binaria.




### Reto 5 — LED Indicador

* **¿Qué se solicitaba?**
Agregar un quinto LED que permaneciera apagado durante el conteo normal y se encendiera cuando el contador llegara a 15.


* **Modificación realizada:**
Se agregó el quinto LED en el pin 12 (`const int LED_INDICADOR = 12;`) y el programa comprueba si el número es 15 (`if (numero == 15) { digitalWrite(LED_INDICADOR, HIGH); } else { digitalWrite(LED_INDICADOR, LOW); }`).


* **Resultado:**
El quinto LED permanece apagado durante los números del 0 al 14. Cuando los cuatro LEDs principales representan `15` (`1111`), el quinto LED se enciende. Al reiniciar el conteo, vuelve a apagarse.





## 2. Simulación en Tinkercad

Se realizaron simulaciones de los diferentes ejercicios utilizando Tinkercad Circuits:

* **Reto 1 — Velocidad:**
  
https://www.tinkercad.com/things/6BHUwJEuLod-contadororiginal-reto-1?sharecode=P9H4-m8a9-OAp5zv23NsaZ7jadrkyq5j7l18FESj2Po

* **Reto 2 — Contador descendente:**
  
https://www.tinkercad.com/things/dJkXtvRqult-contador-descendente-reto-2?sharecode=bHT-gHdlrKlk8YfbD7AWOsHZh8Dz8AWSZinU1XLqGtE

* **Reto 3 — Botón:**
  
https://www.tinkercad.com/things/6vjnUO9Olpc-contador-con-boton-reto-3?sharecode=ZmfMkzTAq3_OMA5oVFTNUEbq7CJMrv5coDMDivIEMvQ

* **Reto 4 — Números pares:**
  
https://www.tinkercad.com/things/fhMxlsXUeku-contador-pares-reto-4?sharecode=qRR2NKfwdzj-MC-l-p91KTk3njIO5Y3OmysD7hIB90w

* **Reto 5 — LED indicador:**
  
https://www.tinkercad.com/things/euHizCUEgh0-contador-led-indicador-reto-5?sharecode=fFCLn9fAUj0qEihQDjeMqNb_v28-671B05H0OY5gl1Q


