typedef struct item{
    char word[30];
} Item;

typedef struct stack{
    unsigned int count;
    Item items[30];
} Stack;

Stack init(Stack obj);
Stack push(Stack obj, char *word);
char* top(Stack obj);
Stack pop(Stack obj);
int is_empty(Stack obj);