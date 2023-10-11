#include <stdio.h>
#include <ctype.h>
#define MAX 10
#define EMPTY '!'
#define DELETED '@'

typedef char Dictionary[MAX];

void initDic(Dictionary D);
int hash(char input);
void displayDic(Dictionary D);
void insert(Dictionary D, char elem);
void delete(Dictionary D, char elem);

int main()
{
    Dictionary myDic;

    initDic(myDic);
    displayDic(myDic);

    insert(myDic, 'A');
    insert(myDic, 'B');
    insert(myDic, 'A');
    displayDic(myDic);
    return 0;
}

void initDic(Dictionary D) {
    int x;
    for (x = 0; x != MAX; ++x) {
        D[x] = EMPTY;
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
    int hashValue;
    for (hashValue = 0; hashValue != MAX; ++hashValue) {
        printf("[%d] => %c ", hashValue, D[hashValue]);
        printf("\n");
    }
}

void insert(Dictionary D, char elem) {
    int hashValue = hash(elem);

    if (D[hashValue] == EMPTY) {
        D[hashValue] = elem;
    } else {
        int x;
        for (x = 0; x != MAX && (D[hashValue] != EMPTY && D[hashValue] != elem); hashValue = (hashValue + 1) % MAX, ++x) {}
        if (D[hashValue] != elem && x != MAX) {
            D[hashValue] = elem;
        }
    }
}

void delete(Dictionary D, char elem) {
    
}