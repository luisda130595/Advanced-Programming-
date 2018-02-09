Practica 3:
El objetivo de esta práctica es el de saber si un robot ha regresado a su punto de origen.
Dicho robot tiene movimientos en dos planos (arriba,abajo) y (derecha, izquierda). Se recibe un 
arreglo con varios comandos. Dichos comandos pueden ser:
U = Up
D = Down
R = Right
L = Left

En caso de que el robot haya llegado a su punto de origen, su desplazamiento en el eje x y y 
debe de ser cero. En caso de que ambas condiciones se cumplan, se regresa TRUE, en cambio, no. 

Descripción:
Se tienen dos tipos de comandos para cada eje. Cada eje se puede ver por separado, pues 
lo que suceda en uno, no afecta lo que pase en el otro. Es por eso que se tiene una estructura con dos variables.
Una que contiene la suma de coordenadas en el eje x y otra del eje y. Al tener dos comandos diferentes para cada eje, 
cada par de comandos es el contrario del otro. Por ejemplo: U es el contrario de D, mientras que R es el contrario de L.
Es por eso que cada comando puede representar un +1 o un -1. El primer paso es el de saber el tamaño del arreglo, en otras
palabras, saber cuantos caracteres contiene. En caso de que este tenga una longitud impar, automáticamente 
se regresa FALSE, pues la única manera en la que el robot llegue al punto de origen es que se presenten la misma cantidad
de comandos contrarios. Una vez que se determina el tamaño del arreglo, proseguimos a recorrerlo elemento por elemento. 
En caso de que un caracter sea U, se suma una unidad en las coordenadas del eje y, en caso de que sea D, se hace lo contrario. 
Para el eje x, se suma una unidad en caso de que el caracter sea L, mientras que se decrementa una unidad cuando este sea
R. Al momento de haber recorrido todo el arreglo, se analiza si las coordenadas de x y y son 0. En caso de que ambas condiciones se cumplan
se regresa TRUE, en el caso contario, se regresa FALSE. 



Efectividad:
El tiempo de ejecución del programa es el siguiente:
n = recorrer el arreglo de caracteres
El tiempo de ejecución total es n, pues la única iteración que se debe hacer es la ya mencionada. 