Practica 1:
El objetivo de dicha práctica es el de encontrar la posición de dos números 
que sumados den la suma de otro, el cual es un parámetro. Por ejemplo:

a=[5,4,8,1,2], t=6

Hay dos combinaciones de números cuya suma dan seis: 5,1 y 4,2. Por lo tanto, los arreglos
que se podrían regresar son: {0,3} y {1,4}, cabe destacar que dichos arreglos contienen 
las posiciones del arreglo en las cuales se encuentran los dos números que sumados dan 
como resultado el parámetro dado. Sin embargo, el programa arrojaría el primer par, 
pues es el primero en la lista.

Contexto:
-Deben ser enteros positivos
-No se presentan números repetidos
-El arreglo siempre va a presentar al menos un par 
-Sólo se debe de encontra un par de números
-El arreglo no está ordenado

Solución:

En el caso de tener un arreglo de sólo dos números, se regresan las posiciones {0,1}

En primera instancia, es necesario acomodar los elementos del arreglo en una hash table, 
misma que tendrá un tamaño igual a la longitud del arreglo que contiene los números con los
que vamos a trabajar
(Tiempo de ejecución = n)

Una vez hecho esto, empezamos a recorrer el arreglo desde la primera posición. 
Al momento de encontrar un número que sea menor al del parámetro dado, 
proseguimos a buscar la posición del número que lo complemente, para llevar a cabo la suma,
en la hashtable.
Ejemplo:
	a = [2,1,7] t=3 En este caso, en la primera posición se encuentra el número dos, mismo
	que es menor a tres y por consecuente, se debe encontrar el número uno. Se busca la 
	posición del número uno en la hashtable a través de una función, misma que regresaría
	el número 1. Al tener ambas posciones, se regresa el siguiente arreglo: {0,1}
En caso de que la hashtable no tenga el número que se busca, el primer número que tenemos de refrencia
se descartaría haciendo que recorramos el arreglo hasta encontrar otro número que sea menor
al parámetro. Una vez que este número es encontrado, proseguimos a realizar los descrito con
anterioridad. Dicho proceso, se repite hasta encontrar el para de números que satisfagan las
condiciones planteadas al inicio del programa. 

Efectividad:
El tiempo de ejecución del programa es el siguiente:
n = recorrer el arreglo para crear la hashtable
n = recorrer el arreglo hasta encontrar el para de números que den la suma
del parámetro dado. Al utilizar hashtable, la búsqueda del segundo elemento es constante
En conclusión, el tiempo de ejecución es el siguiente: n + n 
Haciendo que nuestro algoritmo sea efectivo. 