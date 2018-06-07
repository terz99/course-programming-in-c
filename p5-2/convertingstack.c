/*
JTSK-320112
a5 p2.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"

int main(){

    Stack stack;
    stack = init(stack);

    int val;
    scanf("%d", &val);
    getchar();

    stack = push(stack, val);

    return 0;
}