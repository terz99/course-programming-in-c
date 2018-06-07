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
in binary form. Returns the stack with the new element */
Stack push(Stack obj, int n){

    if(obj.count != 0){
        printf("Stack Overflow\n");
        return obj;
    }

    printf("The binary representation of %d is ", n);

    if(n == 0){
        obj.array[obj.count] = 0;
        obj.count++;
    } else {

        while(n > 0){
            obj.array[obj.count] = n%2;
            obj.count++;
            n /= 2;
        }
    }
    obj = pop(obj);
    return obj;
}

/* Pops the binary number from the stack */
Stack pop(Stack obj){
    
    if(obj.count == 0){
        printf("Stack Underflow\n");
        return obj;
    }

    while(obj.count){
        printf("%d", obj.array[obj.count-1]);
        obj.array[obj.count-1] = 0;
        obj.count--;
    }
    printf(".\n");
    return obj;
}

/* Checks if stack is empty.
Returns 1 if @param obj.count = 0, otherwise 0 */
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

