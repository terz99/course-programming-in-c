/*
JTSK-320112
a5 p3.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

int main(){

    Stack stack;
    stack = init(stack);

    int flag = 1; // flag indicates activity of the loop
    while(flag){

        char str[900];
        fgets(str, 900, stdin);
        str[strlen(str)-1] = '\0';

        if(strcmp(str, "exit") == 0){
            flag = 0;
        } else {

            /* Dividing the words in the string */
            char help[30];
            strcpy(help, "");
            for(int i = 0; i < strlen(str); i++){
                if(str[i] == ' '){
                    stack = push(stack, help);
                    strcpy(help, "");
                } else {

                    char *ch = (char*)malloc(sizeof(str[i]));
                    *ch = str[i];
                    strcat(help, ch);
                    free(ch);

                    if(i == strlen(str)-1){
                        stack = push(stack, help);
                        strcpy(help, "");
                    }
                }
            }

            /* Appending the string in backwards order */
            char newstr[900];
            strcpy(newstr, "");
            while(!is_empty(stack)){
                strcat(newstr, top(stack));
                strcat(newstr, " ");
                stack = pop(stack);
            }

            newstr[strlen(newstr)-1] = '\0';
            if(strcmp(str, newstr) == 0){
                printf("The sentence is palindromic by words!\n");
            } else {
                printf("The sentence is not palindromic by words!\n");
            }
        }
    }

    return 0;
}