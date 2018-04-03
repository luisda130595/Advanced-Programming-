/*Examen 2 README*/

El proposito de este examen es el de generar oraciones invertidas de un cierto numero de 
oraciones que nos es brindado. Lo primero que recibimos es el numero total de oraciones (N).
Una vez obtenido el numero, cada una de las lineas de string que le prosigan contendran 
las diferentes oraciones. 

Inputs:
N-> Numero que indica el total de oraciones por procesar
Oraciones ->  Cada linea de una oracion. Una oracion esta compuesta por un string que contiene
espacios, palabras y puntos. 

Outputs:
Oraciones invertidas ->  Cada una de las oraciones cuyas palabras han sido invertidas 
seran desplegadas. 

Solucion:
Se planteo una solucion un tanto complicada. Al tener una oracion, se propuso crear un stack. 
Dicho stack, seria una conexion entre cada una de las palabras que han sido separadas 
en una oracion. Cabe destacar que al momento de insertar las palabras en el stack, la primera en 
ser separada se encuentra en la parte final de la estructura, mientras que la ultima en ser agregada se encuentra
al inicio. Dicho esto, se puede concluir que al momento de desplegar las palabras, estas ya serian presentadas
en orden inverso. Una vez procesada la oracion, es necesario agregarla a la que encrgada de almacenar
cada una de las oraciones. Una vez hecho todo lo anterior, proseguimos a recorrer cada una de las 
oraciones dentro de la queue y desplegar las palabras que en cada stack de oracion se
ecuentran. 

Complejidad:
n -> Recorrer arreglo de la oracion
n -> recorrer cada oracion

O(n) = n+n