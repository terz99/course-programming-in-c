/*
JTSK-320112
a5 p5.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
    unsigned int age;
    char name[60];
} Person;

Person create_person(const int age, char* name){
    /* Helper function which creates a new instance of Person 
    with @param age and @param name and returns it */
    Person p;
    p.age = age;
    strcpy(p.name, name);
    return p;
}

int desc(const void *a, const void *b){
    /* cmp function to sort floats in descending order */
    const float *va = (const float*)a;
    const float *vb = (const float*)b;
    return *vb - *va;
}

int person_age(const void *a, const void *b){
    /* cmp function to sort struct person increasingly according to @memeber age */
    const Person *va = (const Person*)a;
    const Person *vb = (const Person*)b;
    return va->age - vb->age;
}

int person_name(const void *a, const void *b){
    /* cmp function to sort struct person alphabetically according to @member name */
    const Person *va = (const Person*)a;
    const Person *vb = (const Person*)b;
    return strcmp(va->name, vb->name);
}

int main(){

    int n;
    scanf("%d", &n);
    getchar();

    float *floats = (float*)malloc(n*sizeof(float));
    Person *persons = (Person*)malloc(n*sizeof(Person));
    if(floats == NULL || persons == NULL){
        exit(1); // bad alloc 
    }

    // input floats
    for(int i = 0; i < n; i++){
        scanf("%f", &floats[i]);
        getchar();
    }

    // input persons
    for(int i = 0; i < n; i++){

        char name[60];
        fgets(name, 60, stdin);
        name[strlen(name)-1] = '\0';

        int age;
        scanf("%d", &age);
        getchar();
        persons[i] = create_person(age, name);
    }

    qsort(floats, n, sizeof(float), desc);
    printf("Decreasingly sorted floats:\n");
    for(int i = 0; i < n; i++){
        printf("%.3f", floats[i]);
        if(i < n-1){
            // if it is not the last item in the array, then print space
            printf(" ");
        }
    }
    printf("\n");

    qsort(persons, n, sizeof(Person), person_name);
    printf("Alphabetically sorted structs (name):\n");
    for(int i = 0; i < n; i++){
        printf("%s:%d", persons[i].name, persons[i].age);
        if(i < n-1){
            // if it is not the last item in the array, then print space
            printf(" ");
        }
    }
    printf("\n");

    qsort(persons, n, sizeof(Person), person_age);
    printf("Increasingly sorted structs (age):\n");
    for(int i = 0; i < n; i++){
        printf("%s:%d", persons[i].name, persons[i].age);
        if(i < n-1){
            // if it is not the last item in the array, then print space
            printf(" ");
        }
    }
    printf("\n");

    // mem dealloc
    free(floats);
    free(persons);

    return 0;
}