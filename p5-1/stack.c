#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

/* Initializes the stack */
Stack init(Stack obj){
    obj.count = 0;
    return obj;
}

/* Pushesh a new element (@param n) into the stack (@param obj) 
Returns the stack with the new element */
Stack push(Stack obj, int n){

    printf("Pushing ");

    /* Check if stack is full */
    if(obj.count == 12){
        printf("Stack Overflow\n");
        return obj;
    }

    /* Insert @param n into the stack and increment count */
    printf("%d\n", n);
    obj.array[obj.count] = n;
    obj.count++;
    return obj;
}

/* Pops an element from the stack */
Stack pop(Stack obj){
    
    printf("Popping ");

    if(obj.count == 0){
        /* Check if stack has no elements */
        printf("Stack Underflow\n");
        return obj;
    }

    /* Set the old element to 0 and decrement the count */
    printf("%d\n", obj.array[obj.count-1]);
    obj.array[obj.count-1] = 0;
    obj.count--;
    return obj;
}

/* Returns 1 if @param obj.count = 0, otherwise 0 */
int isEmpty(Stack obj){
    if(obj.count == 0){
        return 1;
    } else {
        return 0;
    }
}

Stack empty(Stack obj){

    printf("Emptying Stack ");
    while(!isEmpty(obj)){
        printf("%d ", obj.array[obj.count-1]);
        obj.array[obj.count-1] = 0;
        obj.count--;
    }
    printf("\n");
    return obj;
}

