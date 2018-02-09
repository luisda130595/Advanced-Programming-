#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

 //STRUCTURES   
typedef struct _coordinates { 
	int rightLeftCoordinates;
	int upDownCoordinates; 
} coordinates;


char isACircle(char movements[], coordinates *trackOfCoord)
{
	
	trackOfCoord->rightLeftCoordinates = 0;
	trackOfCoord->upDownCoordinates = 0;
	
	int numberOfPairMovements = strlen(movements);
	
	if(numberOfPairMovements > 0)
	{
		if(numberOfPairMovements%2==0){
			int counter;
			printf("Array size = %d \n", numberOfPairMovements);
		
			for(counter = 0; counter < numberOfPairMovements; counter++)
			{
				char character = movements[counter];
				printf("Character = %c \n", character);
			
				if(character == 'U')
				{
					trackOfCoord->upDownCoordinates++;
				}
				if(character == 'D')
				{
					trackOfCoord->upDownCoordinates--;
				}
				if(character == 'L')
				{
					trackOfCoord->rightLeftCoordinates++;
				}
				if(character == 'R')
				{
					trackOfCoord->rightLeftCoordinates--;
				}		
			}
			
			printf("Up&Down = %d \n", trackOfCoord->upDownCoordinates);
			if(trackOfCoord->rightLeftCoordinates == 0 && trackOfCoord->upDownCoordinates == 0){
				return TRUE;
			}else
			{
				return FALSE;
			}
			
		}else{
			return FALSE;
		}
		
	}
	else
	{
		return FALSE;
	}
}

int main()
{
	char movements[]= "UD";
	coordinates *trackOfCoord = malloc(sizeof(coordinates));
	
	printf("Array size = %lu \n",strlen(movements));
	
	if(isACircle(movements,trackOfCoord)){
		printf("IS A CIRCLE  \n");
	}else{
		printf("IS NOT A CIRCLE  \n");
	}
	return 0;
	
}
