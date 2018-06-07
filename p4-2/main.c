/*
JTSK-320112
a4 p2.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

int all_upper(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        printf("%c", toupper(str[i]));
    }
    printf("\n");
    return TRUE;
}

int all_lower(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        printf("%c", tolower(str[i]));
    }
    printf("\n");
    return TRUE;
}

int special_print(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        if(islower(str[i])){
            printf("%c", toupper(str[i]));
        } else {
            printf("%c", tolower(str[i]));
        }
    }
    printf("\n");
    return TRUE;
}

int break_loop(char *str){
    return FALSE;
}

int main(){

    char str[100];
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';

    int (*func_ptr[4])(char*) = {all_upper, all_lower, special_print, break_loop};
    /* This flag indicates the activity of the infinite loop */
    int flag = TRUE;
    while(flag){
        int op;
        scanf("%d", &op);
        getchar();
        flag = (*func_ptr[op-1])(str);
    }

    return 0;
}