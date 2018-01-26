#include "uthash.h"
#include "try-catch.h"
#include <stdio.h>

struct my_struct {
    int id;            /* we'll use this field as the key */
    //char name[10];
    int arrayPosition;          
    UT_hash_handle hh; /* makes this structure hashable */
	};


struct my_struct *users = NULL;


void add_user(struct my_struct *s) {
    HASH_ADD_INT( users, id, s );    
}


struct my_struct *find_user(int user_id) {
    struct my_struct *s;

    HASH_FIND_INT( users, &user_id, s );  
    return s;
}

void delete_user(struct my_struct *user) {
    HASH_DEL( users, user);  
}

/*
struct my_struct *numbersHashTable = NULL;

void add_number(struct my_struct *stuctToAdd) 
{
    HASH_ADD_INT( numbersHashTable, id, stuctToAdd );    
}

struct my_struct *find_number(int number) 
{
    struct my_struct *s;

    HASH_FIND_INT( numbersHashTable, &number, s );  
    return s;
}
void delete_number(struct my_struct *number) 
{
    HASH_DEL( numbersHashTable, number);  
}

int[] getNumbers(int[] numbers, int parameter){
	
	int counter;
	int sizeOfNumbersArray = sizeof(numbers)/sizeof(int)
	
	//Filling up the hashtable with the numbers from the array
	for(counter = 0; counter < sizeOfNumbersArray; counter++)
	{
		struct my_struct numToAddStruct = malloc(sizeof(struct my_struct));
		numToAddStruct -> id = numbers[counter];
		numToAddStruct -> arrayPosition = counter;
		add_number(numToAddStruct);
		
	}
	
	//Looking for the pair of numbers that together sum up the parameter
	for(counter = 0; counter < sizeOfNumbersArray; counter++)
	{
		if(numbers[counter] < parameter)
		{
			int nextNumberToLookFor = parameter - numbers[counter];
			struct my_struct *numberFound = find_number(nextNumberToLookFor);
			
			
			
		}
	}
}*/

int main()
{	
	
	struct my_struct *add_struct = malloc(sizeof(struct my_struct));
	add_struct ->id = 50;
	add_struct -> arrayPosition = 0;
	add_user(add_struct);
	struct my_struct *structFound = find_user(10);
	int arrayPosition = structFound -> arrayPosition;
	int sizeOfStruct = sizeof(structFound);
	int idFound = structFound -> id;

	if(structFound)
	{
		printf("Id: %d/n", idFound);
	}
	
	
	
	//printf("%d\t%d\n", structFound.id, structFound.arrayPosition);
	return 0; 
}