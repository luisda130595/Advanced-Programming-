Definición del problema: Batman debe de rescatar a los sobrevivientes atrapados 
en un edificio, para esto, debe brincar de ventana en ventana hasta encontrar la bombas 
que amenazan la vida de los residentes. Cabe destacar que Batman cuenta con un numero 
limitado de brincos para localizar las bombas. Cada turno, el Batman obtiene la dirección 
en la cual se encuentran las bombas, cada turno, la dirección cambia, puesto que Batman 
se va acercando a su objetivo. 

Entradas: 
W - Wight
H - Height
N - Numero se saltos máximo que puede realizar Batman
X0 - Posición inicial en X de Batman
Y0 - Posición inicial en Y de Batman
bombDir - Dirección en la cual se encuentran las bombas. Puede ser (U,D,R,L,UR,UL,DR,DL)

Salidas:
(x y)-posición a la cual debe brincar batman

Solución:

Solución para el primer test
![Solucion 1](shadows_night1.jpg?raw=true "shadows1")
Solución para realizar los movimientos en menos tiempo
![Solucion 2](shadows_night2.jpg?raw=true "shadows2")


Complejidad

O(1) - puesto que el cambio de posiciones se hace al momento. 
Cabe destacar que el algoritmo utilizado solo puede funcionar en el caso de tener un alto 
numero de brincos posible.