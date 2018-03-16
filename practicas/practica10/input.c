#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRINTDEBUG(...) do { \
	char *debug;\
	debug = getenv("DEBUG");\
	if( debug != NULL && !strcmp(debug, "y")){\ 
		fprintf(stderr,format,__VA_ARGS__);\
	}\
	
}while(0)

int main()
{
	int character;
	while(1){
		character = fgetc(stdin);
		if(feof(stdin)){
			break;
		}
		fputc(character, stderr){
		PRINTDEBUG("character = %c\n", character);
		
		}
		
	}
	
	return 0;
}