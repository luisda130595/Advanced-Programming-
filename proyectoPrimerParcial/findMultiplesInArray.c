#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define EXCEPTION 0
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
	int size; 
	//long maxAddition; 
	list_t **table; 
} hash_table_t;


hash_table_t *create_hash_table(int size) { 
	hash_table_t *new_table;  
	if (size<1) return NULL; // invalid size for table  
	 
	// Attempt to allocate memory for the table structure 
	if ((new_table = malloc(sizeof(hash_table_t *))) == NULL){
		return NULL; 
	}
	
	// Attempt to allocate memory for the table itself 
	if ((new_table->table = malloc(sizeof(list_t *) * size)) == NULL) { 
		return NULL; 
		
	}  
	
	// Initialize the elements of the table 
	int counter;
	for(counter=0; counter<size; counter++) new_table->table[counter] = NULL;  
	
	// Set the table's size 
	new_table->size = size; 
	//new_table-> maxAddition = 0;
	
	return new_table;
}

unsigned int hash(hash_table_t *hashtable, int number) { 
	
	// we then return the hash value mod the hashtable size so that it will * fit into the necessary range 
	return number % hashtable->size; 
	
} 

    
list_t *lookup_number(hash_table_t *hashtable, int numberToLookUp) { 

	list_t *list; 
	unsigned int hashval = hash(hashtable, numberToLookUp);  
	// Go to the correct list based on the hash value and see if str is * in the list. If it is, return return a pointer to the list element. * If it isn't, the item isn't in the table, so return NULL.  
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
		
	// Does item already exist? 
	current_list = lookup_number(hashtable, number); 
	
	// If item already exists, add +1 to repetitions. 
	if (current_list != NULL){
		current_list -> repetitions++; 
	}else{
		
		// Attempt to allocate memory for list 
		if ((new_list = malloc(sizeof(list_t))) == NULL) return EXCEPTION;  
		
		
		// Insert into list 
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


 //STRUCTURES   
typedef struct _numbersThatAddUp_ { 
	int number; 
	int size;
	//int numElements;
	struct _numbersThatAddUp_ *next; 
} numbersThatAddUp;


numbersThatAddUp *getNumbersThatAddNumber(long target, hash_table_t *hashtable,int *arrayN, int sizeN){
	
	long tempTarget = target;
	
	numbersThatAddUp *tempNumbersThatAddUp;
	if ((tempNumbersThatAddUp = malloc(sizeof(numbersThatAddUp))) == NULL) return EXCEPTION;
	
	
	//Setting up initial values for the first node
	tempNumbersThatAddUp -> next = NULL;
	tempNumbersThatAddUp -> number = 0;
	tempNumbersThatAddUp -> size = 0;
	//tempNumbersThatAddUp -> numElements = 0;
	
	
	int counter; 
	for(counter = 0; counter < sizeN; counter++)
	{
		
		//printf("Element is: %d \n", arrayN[counter]);
		if(arrayN[counter] < tempTarget)
		{
			printf("Target is: %ld \n", tempTarget);
			tempNumbersThatAddUp -> number = arrayN[counter];
			//tempNumbersThatAddUp -> numElements++;
			
			int nextNumber = tempTarget - arrayN[counter];
			tempNumbersThatAddUp -> size++;
			list_t *arrayElementInHash = lookup_number(hashtable,arrayN[counter]);
			arrayElementInHash -> repetitions--;
			
			
			//printf("Next number is: %d \n", nextNumber);
			
			//Decrementar las repeticiones 
			
			list_t *numberInHash = lookup_number(hashtable, nextNumber);
			
			
			if(numberInHash != NULL && numberInHash -> repetitions > 0){
				
				printf("Entre: \n");
				numbersThatAddUp *newNumberToAddUp;
				if ((newNumberToAddUp = malloc(sizeof(numbersThatAddUp))) == NULL) return EXCEPTION;
				newNumberToAddUp -> number = nextNumber;
				newNumberToAddUp -> next =  tempNumbersThatAddUp;
				//newNumberToAddUp -> numElements++;
				tempNumbersThatAddUp = newNumberToAddUp;
				
			
				return tempNumbersThatAddUp;
			}
			
			
			numbersThatAddUp *newNumberToAddUp;
			newNumberToAddUp -> next =  tempNumbersThatAddUp;
			newNumberToAddUp -> number =  0;
			tempNumbersThatAddUp = newNumberToAddUp;
			
			tempTarget = nextNumber;
			
		}
	} 
	
	return NULL;

}

numbersThatAddUp *getMultiplesFromArray(int *arrayN, int sizeN, hash_table_t *hashtable,long maxAddition)
{
	printf("Max addition is = %ld \n", maxAddition);
	int kmax = maxAddition/sizeN;
	printf("Kmax is = %d \n", kmax);
	
	numbersThatAddUp *numbersThatAddUpNumber;
	
	int counter0;
	for(counter0 = 1; counter0 <= kmax; counter0++)
	{
		long multiple =  counter0 * sizeN;
		printf("Multiple is = %ld \n", multiple);
		
		int counter1;
		
		int tempSize = sizeN;
		for(counter1 = 1; counter1 < sizeN; counter1++)
		{
			
			numbersThatAddUpNumber = getNumbersThatAddNumber(multiple, hashtable, &arrayN[counter1], tempSize);
		
			if(numbersThatAddUpNumber != NULL && numbersThatAddUpNumber -> number != 0){
				return numbersThatAddUpNumber;
			}
			
			tempSize--;
		}
		
	}
	
	return NULL;
	
}

void displayMultipleNumbers(numbersThatAddUp *numbersThatAddUpList)
{
	numbersThatAddUp *tempMultipleNumbers;
	int numberOfElements = 0;
	//printf("Number of elements is: %d \n", numbersThatAddUpList -> numElements);
	
	for(tempMultipleNumbers = numbersThatAddUpList; tempMultipleNumbers != NULL; tempMultipleNumbers = tempMultipleNumbers -> next){
		numberOfElements++;
		printf("Number is: %d \n", tempMultipleNumbers -> number);
	}
	printf("Number of elements: %d \n", numberOfElements);
}

int main()
{
	int N[] = {5,1,2,3,4,1};
	
	printf("Array size is = %ld \n", sizeof(N)/sizeof(int));
	hash_table_t *numbersHashTable;
	numbersHashTable = create_hash_table(100);
	long maxAddition = fillHashtable(numbersHashTable,N,N[0]);
	
	numbersThatAddUp *numbersThatAddUp = getMultiplesFromArray(N,N[0], numbersHashTable,maxAddition);
	displayMultipleNumbers(numbersThatAddUp);
	
	
	return 0;
}
