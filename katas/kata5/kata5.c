#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

#define TRUE 1
#define FALSE 0
#define MAX_SIZE_HASH 100
#define MAX_SIZE_WORD 25

void dictionaryInit(HashInt hash){
	hashInit(&hash,MAX_SIZE_HASH);
}

char **getWords(char *sentence, int sentenceSize, unsigned char *wordsNumber)
{
	//Create arrays that can vary in size
	char **words = malloc(MAX_SIZE_HASH * sizeof(char *)); //list of words
	char *word = malloc(MAX_SIZE_WORD * sizeof(char));//list of characters
	int totalElementsCounter; //total characters in string
	int lettersCounter = 0; //counter of letters per word
	int wordsCounter = 0; //counter of words in the string
	
	for(totalElementsCounter = 0; totalElementsCounter <  sentenceSize; totalElementsCounter++)
	{
		//If analyzed character is one of the following symbols
		if(sentence[totalElementsCounter] == '.'|| sentence[totalElementsCounter] == ',' ||
			sentence[totalElementsCounter] == ';' || sentence[totalElementsCounter] ==':' ||
			sentence[totalElementsCounter] == '_' || sentence[totalElementsCounter] == ' ')
		{
			//Add word to words 
			words[wordsCounter] = (char *)realloc(word,lettersCounter*sizeof(char));
			wordsCounter++;
			lettersCounter = 0;
			
		}else{
			//Add character to temporal word array
			word[lettersCounter] = sentence[totalElementsCounter];
			lettersCounter++;
		}
	}
	
	*wordsNumber = wordsCounter; //Add value to wordsNumber
	words = (char **)realloc(words,wordsCounter * sizeof(char*)); //Resize words array
	//In order to avoid wasting space
	return words;
}

void fillHashTable(HashInt *hash, char **words, unsigned char wordsNumber){
	int counter;
	
	//Insert each word inside the hashtable
	for(counter = 0; counter < wordsNumber; counter++)
	{
		hashInsert(hash, words[counter]);
		
	}
}

//Get the number of times the word appears in the given sentence
int * numberOfRepetitionsPerWord(char *word, HashInt *hash){
		int *wordValue = hashGet(hash,word);
		return wordValue;
}



int main()
{
	char *sentence = "I like like, playing football.";
	int sentenceSize = strlen(sentence);
	int *repetitions;
	unsigned char wordsNumber; 	 
	
	///Begin hashtable 
	HashInt hash;
	dictionaryInit(hash);
	char **words = getWords(sentence, sentenceSize, &wordsNumber);
	fillHashTable(&hash, words, wordsNumber);
	
	//Get number of times the searched word is repeated
	int *numberOfRepetitions;
	numberOfRepetitions = numberOfRepetitionsPerWord("like", &hash);
	
	
	
	/*if(strcmpi("hello","HELLO") == 0){
		printf("YEAH YEAH");
	}*/
	return 0;
}