# 📌 Determinación Experimental de un Punto Silla en una Matriz

Este programa en **C++** encuentra **puntos silla** en matrices cuadradas y analiza el **mejor** y **peor caso** en términos de operaciones ejecutadas.  
Un **punto silla** es un elemento que cumple:  
- Es **menor o igual** que todos los elementos de su fila.  
- Es **mayor o igual** que todos los elementos de su columna.  

---

## 🚀 Características
- 📊 **Generación de matrices** aleatorias o con un punto silla definido.
- 🔍 **Búsqueda de un punto silla** o **todos los puntos silla**.
- ⏱ **Análisis experimental** con conteo de operaciones (`ct`). Con el fin de que se observe graficamente su complejidad en este caso **LINEAL** por lo cual los datos arrojados en el archivo CSV se pueden abrir desde EXCEL y meter a un programa de graficas. 
- 💾 **Salida a archivo CSV** para análisis posterior.
- 🖥 **Impresión de la matriz** en consola.

---

## 🛠 Tecnologías utilizadas
- Lenguaje: **C++ (estilo C)**
- Librerías estándar:  
  ```c
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
