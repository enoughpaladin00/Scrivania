#include<stdio.h>
#include<stdlib.h>

void fibFunction(long int* vec, int num);

int main(int argc, char** argv){
    int fib;

    printf("Inserisci un numero > 2: ");
    scanf("%d", &fib);
    if(fib <= 2) return 1;

    long int* fibv = (long int*)malloc(sizeof(long int) * fib);
    fibFunction(fibv, fib);

    for(int i  = 0; i < fib; i++){
        printf("%ld ", fibv[i]);
    }
    printf("\n");
    free(fibv);
    return 0;
}

void fibFunction(long int* vec, int num){
    int i = 1;
    vec[0] = 0;
    vec[1] = 1;
    while((i + 1) < num){
        vec[i + 1] = vec[i] + vec[i-1];
        i++;
    }
}