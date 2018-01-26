#include <stdio.h>

int main(){
	int a = 250;
	int j,k,l;
	int *p;
	long int d = (long)a * a;
	float f = 4.67;
	int e = 4;
	int c = (int)f +  e;
	p = &a;
	*p = 400;
	p++;
	*p = 5555;
	
	//printf("a = %d, d = %ld, f = %f, e = %d, c = %d\n",a,d,f,e,c); 
	printf("a = %d, p = %p, j = %d, k = %d, l = %d\n",a,p,j,k,l); 
	return 0;
}