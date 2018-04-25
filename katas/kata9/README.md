Problema: Un caracter en UTF8 puede tener una longitud de 1 a 4 bytes y presenta las
siguientes caracteristicas:
-Para un caracter con una longitud de un byte, el primer bit es 0, seguido por su codigo 
unicode. 
-Para un caracter con n-bytes de longitud, los primeros n-bits son 1's, el bit numero 
n+1 es 0, seguido por n-1 numero de bytes con sus dos bits mas significantes '10'.

Entradas:
Arreglo con numeros enteros: int *array

Salida:
TRUE o FALSE

Solucion: 
![Solucion](kata9.jpg?raw=true "kata9")

Complejidad:
O(n). Pues solo se recorre el arreglo una vez. 