#include <stdio.h>
#include <ctype.h>
#define MAX 10
#define EMPTY '!'
#define DELETED '@'

typedef enum {FALSE, TRUE} Boolean;

typedef char Dictionary[MAX];

void initDic(Dictionary *D);
int hash(char input);
Boolean isMember(Dictionary D, char elem);
void displayDic(Dictionary D);
void insert(Dictionary *D, char elem);
void delete(Dictionary *D, char elem);

int main()
{
    Dictionary myDic;

    initDic(&myDic);

    // insert(&myDic, 'A');
    // insert(&myDic, 'B');
    // insert(&myDic, 'C');
    // insert(&myDic, 'D');
    insert(&myDic, 'Z');
    //printf("%d", isMember(myDic, 'C'));
    //printf(" %d", isMember(myDic, 'M'));
    displayDic(myDic);

    // printf("\n");
    // delete(&myDic, 'B');
    // delete(&myDic, 'A');
    // displayDic(myDic);
    return 0;
}

void initDic(Dictionary *D) {
    int x;
    for (x = 0; x != MAX; ++x) {
        (*D)[x] = EMPTY;
    }
}

int hash(char input) {
    int ret;
    switch (input){
        case 'A':
            ret = 2;
            break;
        case 'B':
            ret = 2;
            break;
        case 'E':
            ret = 3;
            break;
        default:
            ret = (toupper(input)-'A');
            break;
    }
    return ret;
}

void displayDic(Dictionary D) {
    int x;
    for (x = 0; x != MAX; ++x) {
        printf("[%d] => %c\n", x, D[x]);
    }
}

void insert(Dictionary *D, char elem) {
    int hashValue = hash(elem), x;
    printf("\nTHIS IS THE HASHVAL ==== %d =====\n", hashValue);

    if ((*D)[hashValue] == EMPTY) {
        (*D)[hashValue] = elem;
    } else {
        for (x = 0; x != MAX && ((*D)[hashValue] != EMPTY && (*D)[hashValue] != DELETED); hashValue = (hashValue + 1) % MAX, ++x) {
            printf("%d------------\n", hashValue);
        }
        
        if ((*D)[hashValue] == EMPTY || (*D)[hashValue] == DELETED) {   
            (*D)[hashValue] = elem;
        }
    }
}

Boolean isMember(Dictionary D, char elem) {
    int hashValue = hash(elem), x;

    for (x = 0; x != MAX && D[hashValue] != elem; hashValue = (hashValue + 1) % MAX, ++x) {}
    return x != MAX ? TRUE : FALSE;
}

void delete(Dictionary *D, char elem) {
    int hashValue = hash(elem);

    int x;
    for (x = 0; x != MAX && (*D)[hashValue] != elem; hashValue = (hashValue + 1) % MAX, ++x) {}
    
    if (x != MAX) {
        (*D)[hashValue] = DELETED;
    }
}