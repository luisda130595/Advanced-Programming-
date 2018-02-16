#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

#define True 1
#define False 0
#define EXCEPTION 0
#define HASHTABLE_SIZE 100

//STRUCTURES   
typedef struct _list_t_ { 
	int number;
	int repetitions; 
	struct _list_t_ *next; 
} list_t;

typedef struct _hash_table_t_ { 
	int size; /* the size of the table */ 
	//long maxAddition; 
	list_t **table; /* the table elements */ 
} hash_table_t;


hash_table_t *create_hash_table(int size) { 
	hash_table_t *new_table;  
	if (size<1) return NULL; /* invalid size for table */ 
	 
	/* Attempt to allocate memory for the table structure */ 
	if ((new_table = malloc(sizeof(hash_table_t *))) == NULL){
		return NULL; 
	}
	
	/* Attempt to allocate memory for the table itself */ 
	if ((new_table->table = malloc(sizeof(list_t *) * size)) == NULL) { 
		return NULL; 
		
	}  
	
	/* Initialize the elements of the table */ 
	int counter;
	for(counter=0; counter<size; counter++) new_table->table[counter] = NULL;  
	
	/* Set the table's size */ 
	new_table->size = size; 
	//new_table-> maxAddition = 0;
	
	return new_table;
}

unsigned int hash(hash_table_t *hashtable, int number) { 
	
	/* we then return the hash value mod the hashtable size so that it will * fit into the necessary range */ 
	return number % hashtable->size; 
	
}

    
list_t *lookup_number(hash_table_t *hashtable, int numberToLookUp) { 

	list_t *list; 
	unsigned int hashval = hash(hashtable, numberToLookUp);  
	/* Go to the correct list based on the hash value and see if str is * in the list. If it is, return return a pointer to the list element. * If it isn't, the item isn't in the table, so return NULL. */ 
	for(list = hashtable->table[hashval]; list != NULL; list = list->next) { 
		if (numberToLookUp == list -> number) 
			return list; 
	} 
	
	return NULL; 
}



int add_number(hash_table_t *hashtable, int number) { 
	list_t *new_list; 
	list_t *current_list; 
	unsigned int hashval = hash(hashtable, number); 
		
	/* Does item already exist? */ 
	current_list = lookup_number(hashtable, number); 
	
	/* If item already exists, add +1 to repetitions. */ 
	if (current_list != NULL){
		current_list -> repetitions++; 
	}else{
		
		/* Attempt to allocate memory for list */ 
		if ((new_list = malloc(sizeof(list_t))) == NULL) return EXCEPTION;  
		
		
		/* Insert into list */ 
		new_list->number = number; 
		new_list->repetitions = 1;
		new_list->next = hashtable->table[hashval]; 		
		hashtable->table[hashval] = new_list;  

	}
	
	
	return 1;
}


long fillHashtable(hash_table_t *hashtable, int *N, int Nsize)
{
	int counter;
	long maxAddition = 0;
	
	for(counter = 1; counter < Nsize; counter++)
	{
		maxAddition += N[counter];
		int addCharacterNumber = add_number(hashtable, N[counter]);
		
		if(addCharacterNumber == EXCEPTION){
			return EXCEPTION;
		}
	}
	
	return maxAddition;
}
