#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

int main(){

    Stack stack;
    stack = init(stack);
    int flag = 1;
    while(flag){

        char ch;
        scanf("%c", &ch);
        getchar();

        if(ch == 's'){
            int val;
            scanf("%d", &val);
            getchar();
            stack = push(stack, val);
        } else if(ch == 'p'){
            stack = pop(stack);
        } else if(ch == 'e'){
            stack = empty(stack);
        } else if(ch == 'q'){
            printf("Quit\n");
            flag = 0;
        } else {
            printf("Unknown command! Try again!\n");
        }
    }

    return 0;
}