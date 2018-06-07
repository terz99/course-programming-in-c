#include <stdio.h>

int main(){

    int t;
    char ch;
    scanf("%d", &t);
    getchar();
    scanf("%c", &ch);
    getchar();

    for(int i = 0; i < t; i++){
        for(int j = 0; j <= i; j++){
            printf("%c", ch);
        }
        printf("\n");
    }

    return 0;
}