#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0
#define EXCEPTION 100
#define WRONGSIZE 8
#define THREECHARS 9
#define NODIGIT 10
#define NOLOWER 11
#define NOUPPER 12
#define SUCCESS 13
/*********************************HASHTABLE CODE**********************************/
 
 //STRUCTURES   
typedef struct _list_t_ { 
	char character;
	int repetitions; 
	struct _list_t_ *next; 
} list_t;

typedef struct _hash_table_t_ { 
	int size; /* the size of the table */ 
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
	
	return new_table;
}

unsigned int hash(hash_table_t *hashtable, char character) { 
	
	/* we then return the hash value mod the hashtable size so that it will * fit into the necessary range */ 
	return character % hashtable->size; 
	
} 

    
list_t *lookup_character(hash_table_t *hashtable, char characterToLookUp) { 

	list_t *list; 
	unsigned int hashval = hash(hashtable, characterToLookUp);  
	/* Go to the correct list based on the hash value and see if str is * in the list. If it is, return return a pointer to the list element. * If it isn't, the item isn't in the table, so return NULL. */ 
	for(list = hashtable->table[hashval]; list != NULL; list = list->next) { 
		if (characterToLookUp == list -> character) 
			return list; 
	} 
	
	return NULL; 
} 

int add_character(hash_table_t *hashtable, char character) { 
	list_t *new_list; 
	list_t *current_list; 
	unsigned int hashval = hash(hashtable, character); 
		
	/* Does item already exist? */ 
	current_list = lookup_character(hashtable, character); 
	
	/* If item already exists, add +1 to repetitions. */ 
	if (current_list != NULL){
		current_list -> repetitions++; 
	}else{
		
		/* Attempt to allocate memory for list */ 
		if ((new_list = malloc(sizeof(list_t))) == NULL) return EXCEPTION;  
		
		
		/* Insert into list */ 
		new_list->character = character; 
		new_list->repetitions = 1;
		new_list->next = hashtable->table[hashval]; 		
		hashtable->table[hashval] = new_list;  
	}
	
	
	return 1;
}



/*********************************PROGRAM CODE**********************************/
int isLowerCase(char inputCharacter)
{
	if (inputCharacter >= 'a' && inputCharacter <= 'z') 
	{
        return True;
    }
    return False;
}

int isUpperCase(char inputCharacter)
{
	if (inputCharacter >= 'A' && inputCharacter <= 'Z') 
	{
        return True;
    }
    return False;
}


int fillHashtable(hash_table_t *hashtable, char *password, int passwordSize)
{
	int counter;
	
	for(counter = 0; counter < passwordSize; counter++)
	{
		int addCharacterNumber = add_character(hashtable, password[counter]);
		
		if(addCharacterNumber == EXCEPTION){
			return EXCEPTION;
		}
	}
}



int strongPasswordChecker(hash_table_t *hashtable, char *password, int passwordSize)
{
	int counter;
	int hasThreeCharacters = False;
	int hasADigit = False;
	int hasUpperCase = False;
	int hasLowerCase = False;
	
	if( passwordSize > 20 ||  passwordSize < 6) return WRONGSIZE;
	
	for(counter = 0; counter < passwordSize; counter++)
	{
		printf("Password char = %c \n", password[counter]);
		if(isLowerCase(password[counter])) hasLowerCase = True;
		if(isUpperCase(password[counter])) hasUpperCase = True;
		if(isdigit(password[counter])) hasADigit = True;
		
		int limitThreeCharacters = passwordSize - 3;
		
		list_t *characterInfo;
		characterInfo = lookup_character(hashtable, password[counter]);
		
		if(characterInfo != NULL){
			
			if(characterInfo -> repetitions >= 3 && counter <= limitThreeCharacters){
				char character1 = password[counter];
				printf("Char 1 = %c \n", character1);
				char character2 = password[counter+1];
				printf("Char 2 = %c \n", character2);
				char character3 = password[counter+2];
				printf("Char 3 = %c \n", character3);
				
				if(character1 == character2 && character1 == character3){
					return THREECHARS;
				}else{
				 	characterInfo -> repetitions--;
				 }
			}
			
		}else{
			return EXCEPTION;
		}
	
	}
	
	if(!hasLowerCase && !hasUpperCase && !hasADigit) return NOLOWER + NOUPPER + NODIGIT;
	if(!hasLowerCase && !hasUpperCase) return NOLOWER + NOUPPER;
	if(!hasLowerCase && !hasADigit) return NOLOWER + NODIGIT;
	if(!hasUpperCase && !hasADigit) return NOUPPER + NODIGIT;
	if(!hasLowerCase) return NOLOWER;
	if(!hasUpperCase) return NOUPPER;
	if(!hasADigit) return NODIGIT;
	
	if(hasLowerCase && hasUpperCase && hasADigit) return SUCCESS;

}




int main()
{
	char password[] = "holaa1aa1cjhiijaaab";
	int passwordSize = strlen(password);
	printf("Password size = %d \n", passwordSize);
	
	hash_table_t *passwordHashTable;
	passwordHashTable = create_hash_table(passwordSize);
	int canFillHashtable = fillHashtable(passwordHashTable, password, passwordSize);
	
	if(canFillHashtable ==  EXCEPTION)
	{
		printf("ERROR WHILE FILLING UP HASHTABLE \n");
	}
	
	if(passwordHashTable != NULL){
		printf("HASHTABLE CREATED \n");
		
		int isPasswordSuccessfull = strongPasswordChecker(passwordHashTable, password, passwordSize);
		
		if(isPasswordSuccessfull == (NOLOWER + NOUPPER + NODIGIT))
			printf("PASSWORD IS COMPLETELY WRONG \n");
		if(isPasswordSuccessfull == (NOLOWER + NOUPPER))
			printf("PASSWORD HAS NEITHER LOWER NOR UPPER \n");
		if(isPasswordSuccessfull == (NOLOWER + NODIGIT))
			printf("PASSWORD HAS NEITHER LOWER NOR DIGIT \n");
		if(isPasswordSuccessfull == (NOUPPER + NODIGIT))
			printf("PASSWORD HAS NEITHER UPPER NOR DIGIT \n");
		if(isPasswordSuccessfull == (NOLOWER))
			printf("PASSWORD HAS NO LOWER \n");
		if(isPasswordSuccessfull == (NOUPPER))
			printf("PASSWORD HAS NO UPPER \n");
		if(isPasswordSuccessfull == NODIGIT)
			printf("PASSWORD HAS NO DIGIT \n");
		if(isPasswordSuccessfull  == THREECHARS)
			printf("PASSWORD HAS THREE CONTINOUS CHARACTERS \n");
		if(isPasswordSuccessfull == WRONGSIZE)
			printf("PASSWORD MUST HAVE BETWEEN 6 AND 20 CHARS \n");
		if(isPasswordSuccessfull == SUCCESS)
			printf("SUCCESFULL PASSWORD \n");
		
		
	}else{
		printf("HASHTABLE COULD NOT BE CREATED \n");
	}	
	
	return 0;
	
	
}