#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 50

char* remove(char* str, const char* sub){
    char* index = strstr(str, sub);
    if(index == NULL) return str;
    int index_i = index - str;
    int stop = index_i + strlen(sub);
    for(int i = stop; i < strlen(str); i++){
        str[i - strlen(sub) - 1] = str[i + strlen(sub) + 1];
    }

}

int main(int argc, char** argv){
    char myWord[MAX_LENGTH];
    char subWord[MAX_LENGTH];

    printf("Word to check: ");
    fgets(myWord, MAX_LENGTH, stdin);
    printf("Word to be removed: ");
    fgets(subWord, MAX_LENGTH, stdin);
    fflush(stdin);

    char* myWord = remove(myWord, subWord);



}