#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 10

typedef struct node{
    char data;
    struct node *link;
} *LIST;

typedef LIST Dictionary[MAX];

int Hash(char elem);
void insertSorted(Dictionary D, char elem);
void initDictionary(Dictionary D);
void displayDictionary(Dictionary D);
// void delete(Dictionary D, char elem);

int main(){
    Dictionary D;
    initDictionary(D);

    char letter[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int letterLen = sizeof(letter) / sizeof(letter[0]);
    int x;

    displayDictionary(D);
    // printf("%d", letterLen);

    for(x = 0; x < letterLen - 1; x++){
        int index = Hash(letter[x]);
        printf("%c - %d\n",letter[x], index);
        insertSorted(D, letter[x]);
    }

    displayDictionary(D);
}

int Hash(char elem){
    return (toupper(elem) - 'A') % MAX;
}

void initDictionary(Dictionary D){
    int x;

    for(x = 0; x < MAX; x++){
        D[x] = NULL;
    }
}

void displayDictionary(Dictionary D){
    int x;
    LIST trav;

    for(x = 0; x < MAX; x++){
        printf("[%d] = ", x);
        for(trav = D[x]; trav != NULL; trav = trav->link){
            printf("%c -> ", trav->data);
        }
        printf("NULL");
        printf("\n");
    }
    printf("\n");
}

void insertSorted(Dictionary D, char elem){
    int index = Hash(elem);
    LIST *trav;

    for(trav = &D[index]; *trav != NULL && (*trav)->data < elem; trav = &(*trav)->link){}

    LIST temp = (LIST)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = elem;
        temp->link = *trav;
        *trav = temp;
    }
}