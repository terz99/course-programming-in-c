/*
JTSK-320112
a4 p4.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct person{
    char name[30];
    int age;
};

int sort_name(const struct person a, const struct person b){
    
    /* Sort by name */

    int cmp = strcmp(a.name, b.name);
    if(cmp == 0){
        return a.age - b.age;
    } else {
        return cmp;
    }
}

int sort_age(const struct person a, const struct person b){
    
    /* Sort by age */

    if(a.age == b.age){
        return strcmp(a.name, b.name);
    } else {
        return a.age - b.age;
    }
}

void bubble_sort(struct person *arr, int n, int (*cmp)(const struct person, const struct person)){

    /* Bubble sort algorithm */

    int swapped = 1;
    while(swapped){

        swapped = 0;
        for(int i = 1; i < n; i++){

            if(cmp(arr[i-1], arr[i]) > 0){
                struct person tmp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = tmp;
                swapped = 1;
            }
        }
    }
}

int main(){

    int num_elems;
    scanf("%d", &num_elems);
    getchar();

    struct person persons[num_elems];

    for(int i = 0; i < num_elems; i++){

        // enter name
        char tmp_name[30];
        fgets(tmp_name, sizeof(tmp_name), stdin);
        tmp_name[strlen(tmp_name)-1] = '\0';

        // enter age
        int age;
        scanf("%d", &age);
        getchar();

        // assign to person
        strcpy(persons[i].name, tmp_name);
        persons[i].age = age;
    }

    /* Sort by name */
    bubble_sort(persons, num_elems, sort_name);
    for(int i = 0; i < num_elems; i++){
        printf("{%s, %d}; ", persons[i].name, persons[i].age);
    }
    printf("\n");

    /* Sort by age */
    bubble_sort(persons, num_elems, sort_age);
    for(int i = 0; i < num_elems; i++){
        printf("{%s, %d}; ", persons[i].name, persons[i].age);
    }
    printf("\n");


    return 0;
}