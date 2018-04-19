Problema: Los pasajeros de vuelo estan moletestos pues hay veces que no llegan a terminar 
de ver dos peliculas en su vuelo, pues estas duran mas que el mismo. Es por eso que el 
sistema de entretenimiento debe de avisar si existen dos filmes que duren exactamente lo 
mismo que el vuelo.

Entradas: 
-flight_length: Variable que contiene el valor, en entero, de la duracion del vuelo
-movies_lenght: Arreglo que contiene la duracion, en minutos, de todos los filmes 
disponibles en el centro de entretenimiento

Salidas:
-True or false: Dependiendo de la existencia de un par de filmes que sea igual a la dura-
cion del filme

Solucion:
Se empleo un algoritmo de dynamic programming. Esto para evitar usar recursion y 
tener un mejor manejo de memoria. 

Complejidad:
O(n*log(n))