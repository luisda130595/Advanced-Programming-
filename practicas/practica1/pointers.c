#include <stdio.h>

int main(){
	int a[5]= {1,2,3,4,5}; //Si no doy un valor C pone 0
	int *pa;
	pa = a; //Posicion cero del arreglo
	*pa = 27;
	pa[2] = 45;
	*(pa + 3) = 200; //Cambiar el valor del arreglo que se encuentre tres posiciones adelante 
					//de las demas
	int i;
	for(i=0; i<5; i++){
		printf("a[%d} = %d ",i,a[i]);
	}
	
	printf("\n");
	return 0;
}