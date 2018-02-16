Proyecto 1: Encontra el múltiplo

La entrada del programa contiene una N cantidad de números enteros positivos. Cada uno
de estos números no es mayor a 15000. De la misma manera, estos pueden no ser diferentes, por lo cual, 
dos o más de estos pueden llegar a ser los mismos. La finalidad del programa, es la de entregar una serie de 
números, de la serie N, cuya suma sea múltiplo de N, o en otras palabras N*k=suma de números escogidos (siendo
k un número entero cualquiera). 

-Contexto:

Time Limit: 2 seconds

Memory limit: 64 MB

-La serie de números de entrada tiene una longitud máxima de 10000
-Cada uno de los números no es mayor a 15000
-La longitud del arreglo que de números escogidos debe tener una longitud mayor o igual a uno 
o igual o menor a N.
-La entrada contiene el número de elementos en la primera posición y en las posiciones posteriores
contiene a los  N elementos.
-La salida contiene el número de elementos escogidos y en las posiciones posteriores contiene 
a los elementos escogidos.


-Breakdown:
![Programacion de proyecto1](proyecto1.jpeg?raw=true "proyecto1")
![Programacion de proyecto1](proyecto2.jpeg?raw=true "proyecto1")
![Programacion de proyecto1](proyecto3.jpeg?raw=true "proyecto1")

-Solucion:
La solución planteada es la siguiente:
De primera instancia, tenemos que encontrar el mayor factor (k) posible. Esto se obtiene dividiendo la 
suma de todos los elementos del arreglo (la mayor suma existente), entre el tamaño de dicho arreglo, ya que 
k*N = suma de múltiplos. Una vez que se ha hecho esto, proseguimos a anaizar si existe la suma de múltiplos para cada valor 
N*k.

Después, proseguimos a analizar cada uno de los elementos del arreglo de números, para ver si existe una serie de números 
cuya suma de elementos sea igual a N*k. En caso de no encontrar solución con un elemento, analizamos el siguiente, y así
hasta recorrer el arreglo.  

La solución que se propuso no es la indicada, pues ésta tarda mucho en ejecutarse. De la misma manera, se puede 
afirmar que el programa no funcionaría del todo, en caso de que se enfrente a la peor situación 
en la que pueda estar, es decir, que el arreglo esté lleno (N = 10000) y que tenga elementos iguales a 14999. 
Esto, debido a que no se encontraría número alguno que satisfaciera las condiciones del problema. Al suceder esto, 
recorreríamos todos los factores posibles y cada uno de los elementos del arreglo en sus combinaciones posibles. Es decir, 
comenzaríamos a ver si el elemento 0 tiene elementos que satisfagan las condiciones, como no los hay, seguiríamos con 
el elemento 1 y así hasta terminar con el arreglo, sin encontra solución alguna, haciendo que el tiempo 
de ejecución sea excesivamente grande.

-Analisis:
Recorrer el número de combinaciones posibles de k*N = n
Recorrer el arreglo para encontrar las combinaciones de múltiplos por posición = n
Recorrer el arreglo para encontrar dichas combinaciones = n

Tiempo de ejecución =n*n*n
