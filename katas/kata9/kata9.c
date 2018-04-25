#include <stdlib.h>
#include <stdio.h>

#define BYTE_AND_NUM_CHARS 240
#define BYTE_AND_FIRST_CHARS 192
#define TRUE 1
#define FALSE 0

unsigned char check_number_bytes(int *array)
{
	unsigned char temp_byte_and = BYTE_AND_NUM_CHARS & (unsigned char)array[0];
	
	printf("Temp_byte_and is: %d\n", temp_byte_and);

	
	if(temp_byte_and < 128){
		return 1;
	}else if(temp_byte_and == 192){
		return 2;
	}else if(temp_byte_and == 224){
		return 3;
	}else if(temp_byte_and == 240){
		return 4;
	}else{
		return 0;
	}
}

char check_UTF(int *array){
	unsigned char num_bytes = check_number_bytes(array);
	
	if(num_bytes == 1){
		return TRUE;
		
	}else if(num_bytes == 0){
		return FALSE;
	}else{
		unsigned char counter;
		for(counter = 1; counter < num_bytes; counter++){
			unsigned char utf_character = (unsigned char) array[counter];
			
			printf("utf_character is: %d\n", utf_character);
			
			if((utf_character & BYTE_AND_FIRST_CHARS) != 128){
				return FALSE;
			}
		}
		
		return TRUE;
	}
}

int main()
{
	int array[] = {197,130,1};
	//int array[] = {235,140,4};
	char bool = check_UTF(array);
	if(bool){
		printf("TRUE\n");
	}else{
		printf("FALSE\n");
	}
	return 0;
}