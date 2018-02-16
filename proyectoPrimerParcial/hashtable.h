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


hash_table_t *create_hash_table(int);

unsigned int hash(hash_table_t *, int);

list_t *lookup_number(hash_table_t *, int);


int add_number(hash_table_t *, int);

long fillHashtable(hash_table_t *, int *, int);