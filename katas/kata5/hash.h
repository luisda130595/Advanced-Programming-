typedef struct e {
    char *key;
    int value;
} Element;

typedef struct d {
    Element *elements;
    unsigned count;
    unsigned length;
} HashElement;

typedef struct h {
    HashElement *data;
    unsigned size;
    ///
} HashInt;

void hashInit(HashInt *, int);
void hashInsert(HashInt *, char *);
int * hashGet(HashInt *,char *); 