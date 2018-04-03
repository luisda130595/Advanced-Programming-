/*
La manera en la que voy a resolver el problema es la siguiente:
Primero, voy a  analizar el numero de lineas que me van a llegar como input. 
Una vez que se cual es el numero de lineas. Voy a procesar cada una de las siguientes, mediante un metodo 
que va a separar cada oracion en palabras. Dicho metodo va a agregar cada una de las palabras en una estructura, misma
que va contenter un link a la estructura siguiente. Dicha linked list va a contener las palabras 
de una oracion. Cabe destacar que cada una de las palabras va a ser agregadar a la Linked List de estructuras de manera inversa.
Al hacer eso, lo unico que va a ser necesario es recorrer la lista de inicio a fin.
*/
#include <stdio.h>
#include <string.h>

typedef struct w {
	char characters[11];
	struct s *next_word;
}Word;

typedef struct sentence{
	Word *sentence;
	struct sentence *next_sentence;
	int number_of_words;
}Sentence;

/*Methods used for separating the sentence in words*/

void word_assembly(char *c,int index, int lenght ) {
   printf ("\n");
   int i = index - lenght;
    do {
        putchar (c[i]);
        i++;
    } while (c[i] != ' ');
    return;
}

void separate_sentence_in_words(char *sentence_not_separated,Word *sentence)
{
	int i;
	int length = 0; 
	
	
	for (i=0; sentence_not_separated[i] != '\0'; i++) {
    	if (sentence_not_separated[i] == ' ' || sentence_not_separated[i] == '.') {
    		word_assembly(sentence -> characters, i, length);
    		iWord *temp_word = malloc(sizeof(Word *));
    		temp_word -> next_word = sentence;
    		sentence = temp_word;
    		
    		length = 0;
    	}

    	length++;
  	}
  	
}

void create_separated_sentence(Word *sentence_separated, Sentence *sentence){
	//Llamamos a este metodo cada vez que haya una nueva oracion por procesar.
	//Primero, llamamos a la funcion separate_sentence_in_words
	//Una vez hecho esto, agregamos esta oracion a nuestra linked list de oraciones
}

/*Method for making a whole sentence from the words obtained*/
void display_sentences(Sentence *sentences, int N){
	int counter;
	for(counter = 0; counter < N; counter++){
		Word *temp_sentence = malloc(sizeog(Word *));
		temp_sentence = sentences -> sentence;
		
		
	}
}

/*Inicializar valores de las estructuras*/
void structures_init(Word *word, Sentence *sentence){
	//Inicializar valores
}



int main(){
	int N = argv[0]; //Hacer cast
	
	//Obtener las oraciones que formen parte de los argumentos 
	//Inicializar las estructuras poniendo sus valores iniciales en NULL y ceros
	//Por cada oracion que haya hacer que dicha oracion sea modificada separate sentence in words 
	//Agregar las oraciones al grupo de oraciones
	
	
	

	return 0;
}


