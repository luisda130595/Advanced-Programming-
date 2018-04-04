#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void parse_lines(char *line){
	
}

int toDigit(char character){
	int result =  character - '0';
	return result;
}

void set_remainders(char *remainder_0, char *remainder_1, char *remainder_2, char *remainder_3, char P, char N, char *groups){
	char counter;
	
	
	
	for(counter = 0; counter <  N; counter++){
		char digit = toDigit(groups[counter]);
		//int digit =toDigit(groups[counter]);
		printf("Digit is: %d\n",digit);
		char remainder = digit % P;
		
		
		switch(remainder){
			case 0:
				*remainder_0 = *remainder_0 + 1;
				break;
			case 1:
				*remainder_1 = *remainder_1 + 1;
				break;
			case 2:
				*remainder_2 = *remainder_2 + 1;
				break;
			case 3:
				*remainder_3 = *remainder_3 + 1;
				break;
			default:
				printf("INVALID REMAINDER DETECTED \n");
			
		}
	}
}

char formula_for_same_remainders(char numGroups)
{
	char tempNum = 0;
	/*only for P = 4 OR 3*/
	/*remainder 2 doesn't count in the case of P = 4*/
	if(numGroups % 2 == 0){
		tempNum = numGroups / 2;
	}else{
	
		char tempNum = numGroups/2 +1;
		tempNum = numGroups - tempNum;
	}
	
	return tempNum;
}

char formula_for_different_remainders(char remainder1, char remainder2){
	char tempNum = 0;
	if(remainder1 ==0 & remainder2 ==0){
		return 0;
	}else if(remainder1 > remainder2){
		tempNum = remainder2 + 1;

	}else if(remainder1 == remainder2){
		tempNum = remainder1;

	}else{
		tempNum = remainder1 + 1;

	}
	
	return tempNum;
}


char get_groups_new_bars(char *remainder_0, char *remainder_1, char *remainder_2, char *remainder_3, char P){
	char totalGroups = 0;

	switch(P){
		case 2:
			//Add up the number of groups whose remainder is 0 when divided by 2
			totalGroups += *remainder_0;
			printf("First analysis P2, totalGroups = %d\n",totalGroups);
			//Add up the result of groups whose remainder is 1 when divided by 2
			if(*remainder_1 % 2 == 0){
				totalGroups = totalGroups + *remainder_1 / 2;
			}else{
				totalGroups = totalGroups + (*remainder_1 / 2) + 1;
			}
			printf("Second analysis P2, totalGroups = %d\n",totalGroups);
			return totalGroups;
		
		
		case 3:
			//Add up the number of groups whose remainder is 0 when divided by 3
			totalGroups += *remainder_0;
			printf("First analysis P3, totalGroups = %d\n",totalGroups);
			//Add up the result from the pairs of different groups of remainders
			totalGroups += formula_for_different_remainders(*remainder_1, *remainder_2);
			printf("Second analysis P3, totalGroups = %d\n",totalGroups);
			
			if(*remainder_1 > *remainder_2){
				*remainder_1 = *remainder_1 - formula_for_different_remainders(*remainder_1, *remainder_2);
				*remainder_2 = 0;
		
			}else if(*remainder_1 == *remainder_2){
				
				*remainder_1 = 0;
				*remainder_2 = 0;
		
			}else{
				*remainder_2 = *remainder_2 - formula_for_different_remainders(*remainder_1, *remainder_2);
				*remainder_1 = 0;
			}
	
			//Add up the result from the pairs of equal groups of remainders
			char last_remainder_P3 = *remainder_1 || *remainder_2;
			totalGroups += formula_for_same_remainders(last_remainder_P3);
			printf("Third analysis P3, totalGroups = %d\n",totalGroups);
			
			return totalGroups;
			 
		
		case 4:
		
			//Add up the number of groups whose remainder is 0 when divided by 4
			printf("First analysis P4, totalGroups = %d\n",totalGroups);
			totalGroups += *remainder_0;
			//Add up the groups when pairing all the ones that have 2 as a remainder
			printf("Second analysis P4, totalGroups = %d\n",totalGroups);
			if(*remainder_2 % 2 == 0){
				totalGroups = totalGroups + *remainder_2 / 2;
			}else{
				totalGroups = totalGroups + (*remainder_2 / 2) + 1;
				
			}
			*remainder_2 = 0;
			//Add up the pair composed by groups with remainders of three and one
			printf("Third analysis P4, totalGroups = %d\n",totalGroups);
			totalGroups += formula_for_different_remainders(*remainder_1, *remainder_3);
			
			if(*remainder_1 > *remainder_3){
				*remainder_1 = *remainder_1 - formula_for_different_remainders(*remainder_1, *remainder_3);
				*remainder_3 = 0;
		
			}else if(*remainder_1 == *remainder_3){
				
				*remainder_1 = 0;
				*remainder_3 = 0;
		
			}else{
				*remainder_3 = *remainder_3 - formula_for_different_remainders(*remainder_1, *remainder_3);
				*remainder_1 = 0;
			}
			
			//Add up the result from the pairs of equal groups of remainders
			printf("Fourth analysis P4, totalGroups = %d\n",totalGroups);
			char last_remainder_P4 = *remainder_1 || *remainder_3;
			totalGroups += formula_for_same_remainders(last_remainder_P4);
			
			return totalGroups;
			
			
			
		default:
		printf("INVALID PORTIONS \n");
	}

}

int main(){
	char T;
	//char N = 4;
	//char P = 3;
	//char G[] = {'4','5','6','4'};
	//char N = 4;
	//char P = 2;
	//char G[] = {'4','5','6','4'};
	char N = 3;
	char P = 3;
	char G[] = {'1','1','1'};
	char getGroups = 0;
	
	char remainder_0 = 0;
	char remainder_1 = 0;
	char remainder_2 = 0;
	char remainder_3 = 0;
	
	set_remainders(&remainder_0, &remainder_1, &remainder_2, &remainder_3, P, N, G);
	
	printf("Remainder_0 is: %d\n",remainder_0); 
	printf("Remainder_1 is: %d\n",remainder_1); 
	printf("Remainder_2 is: %d\n",remainder_2); 
	printf("Remainder_3 is: %d\n",remainder_3); 
	
	getGroups = get_groups_new_bars(&remainder_0, &remainder_1, &remainder_2, &remainder_3, P);
	printf("Groups that consumed new bars: %d\n", getGroups);
	
	return 0;
}