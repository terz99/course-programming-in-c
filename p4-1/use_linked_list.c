/*
JTSK-320112
a4 p1.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(){

    struct linked_list *myll = NULL;
    /* The flag is used to indicate the activity of 
    the infinite while loop */
    int flag = 1;
    while(flag){

        char ch;
        scanf("%c", &ch);
        getchar();

        int val;
        switch(ch){
            case 'a':
                scanf("%d", &val);
                getchar();
                myll = push_back(myll, val);
                break;
            case 'b':
                scanf("%d", &val);
                getchar();
                myll = push_front(myll, val);
            break;
            case 'r':
                myll = pop_front(myll);
            break;
            case 'p':
                print_linked_list(myll);
            break;
            case 'q':
                myll = dispose_linked_list(myll);
                /* Deactivate the flag and stop the program */
                flag = 0;
            break;
            default:
                /* Handling the invalid outputs */
                printf("Unknown command. Try again\n");
        }
    }

    return 0;
}