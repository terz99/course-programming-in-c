#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

Stack init(Stack obj){

    /* Initializing the stack */

    obj.count = 0;
    for(int i = 0; i < 30; i++){
        strcpy(obj.items[i].word, "");
    }
    return obj;
}

Stack push(Stack obj, char *word){

    /* Pushesh a new element into the stack if the size
    is less than 30 */

    if(obj.count == 30){
        printf("Stack Overflow\n");
        return obj;
    }

    strcpy(obj.items[obj.count].word, word);
    obj.count++;
    return obj;
}

char* top(Stack obj){
    /* Returns the top element of the stack
    without deleting it from the stack */
    char *ret = (char*)malloc(strlen(obj.items[obj.count-1].word)*sizeof(char));
    strcpy(ret, obj.items[obj.count-1].word);
    return ret;
}

Stack pop(Stack obj){
    /* Deletes the top element from the stack */
    if(obj.count == 0){
        printf("Stack Underflow\n");
        return obj;
    }

    strcpy(obj.items[obj.count-1].word, "");
    obj.count--;
    return obj;
}

int is_empty(Stack obj){
    /* Checks if stack is empty
    Returns 1 if it is empty, 0 otherwise */
    return ((obj.count) ? 0 : 1);
}