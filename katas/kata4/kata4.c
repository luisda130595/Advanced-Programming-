#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

char checkCommas(int counter, char *string, int stringSize)
{
	if(counter >= 2 & counter < (stringSize - 3))
    {
    	//Determine if there aren't any other commas in the next and previous two positions
      	char prevChar1;
      	char prevChar2;
      	char prevChar3;
      						
      	char nextChar1;
      	char nextChar2;
      	char nextChar3;
      						
		if(counter == 2){
			prevChar1 = string[counter-1];
      		prevChar2 = string[counter-2];
      							
      		nextChar1 = string[counter+1];
      		nextChar2 = string[counter+2];
      		nextChar3 = string[counter+3];
      							
      		if(prevChar1 == ',' | prevChar2 == ',' | nextChar1 == ',' | nextChar2 == ',' | nextChar3 == ','){
      			return FALSE;
      		}else{
      			return TRUE;
      		}
							
		}else{
			prevChar1 = string[counter-1];
      		prevChar2 = string[counter-2];
      		prevChar3 = string[counter-3];
      							
      		nextChar1 = string[counter+1];
      		nextChar2 = string[counter+2];
      		nextChar3 = string[counter+3];
							
			if(prevChar1 == ',' | prevChar2 == ',' | prevChar3 == ',' | nextChar1 == ',' | nextChar2 == ',' | nextChar3 == ','){	
				return FALSE;	
			}else{
      			return TRUE;
      		}
		}
							
      						
    }else{
      	return FALSE;
    }
}

char isANumber(char *string)
{

	char pointsCounter = 0;
	char eCounter = 0;
	char commasCounter = 0;
	
	int stringSize = sizeof(string)/sizeof(char);
	
	if(stringSize >= 255)
		return FALSE;
		
	int counter;
	
	for(counter = 0; counter < stringSize; counter++)
	{
		if(!isdigit(string[counter])){
			//Determine if character is valid 
			switch(string[counter]) {
      			case ',' :
         			//If points counter or e counter is bigger than 0, this means that we are situated after them
         			if(eCounter > 0)
      					return FALSE;
      					
      				if(pointsCounter > 0)
      					return FALSE;
      					
      				if(!(commasCounter > 0 && checkCommas(counter, string, stringSize) == TRUE))
      					return FALSE;
      	
         			break;
         			
      			case '.' :  
      				//If e counter is bigger than 0, this means that we are situated after an e    			
      				if(pointsCounter > 0)
      					return FALSE;
      				
      				if(eCounter > 0)
      					return FALSE;
      					
      				pointsCounter++;
      			
      				break;
      			case 'e' :
         			
         			if(pointsCounter > 0)
      					return FALSE;
      				
      				if(eCounter > 0)
      					return FALSE;
      					
         			eCounter++;  			
         			
         			break;
         		case '+':
         		
         			//Check if the symbol goes after an e or is located at the beginning
         			if(!(string[counter-1]=='e' | counter == 0))
         				return FALSE;
         			
         			break;
         			
         		case '-':
         			//Check if the symbol goes after an e or is located at the beginning
         			if(!(string[counter-1]=='e' | counter == 0))
         				return FALSE;
         			
         			break;
         			
      			default :
         			return FALSE;
         			
   			}
   			 			
   		}
						
	}
	
	return TRUE;
			
}

int main(){
	
	char number[] = "4e42";
	
	if(isANumber(number))
		printf("IS A NUMBER \n");
		
		
	return 0;
}
