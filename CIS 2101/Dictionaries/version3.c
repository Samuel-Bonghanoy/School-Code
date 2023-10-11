#include <stdio.h>
#define MAX 10
#define EMPTY '!'
#define DELETED '@'

typedef enum {FALSE, TRUE} Boolean;

typedef struct {
    int data;
    int next;
}nodeType;

typedef struct {
    nodeType Nodes[MAX];
    int avail;
}Dictionary;

int hash(int elem);
int allocSpace(Dictionary *D);
void initDict(Dictionary *D);
void displayDict(Dictionary D);
void insertDict(Dictionary *D, int elem);

int main()
{
    Dictionary myDic;
    
    return 0;
}

int hash(int elem) {
    return elem % MAX;
}

int allocSpace(Dictionary *D) {
    int retVal = D->avail;

    if (D->avail != -1) {
        D->avail = D->Nodes[D->avail].next;
    }
    return retVal;
}

void initDict(Dictionary *D) {
    int x;
    for (x = 0; x != MAX; ++x) {
        if (x < MAX / 2) {
            D->Nodes[x].next = -1;
            D->Nodes[x].data = EMPTY;
        } else {
            D->Nodes[x].next = x + 1;
        }
    }
    D->Nodes[MAX - 1].next = -1;
    D->avail = MAX / 2;
}

void displayDict(Dictionary D) {
    int x, trav;
    for (x = 0; x != MAX / 2; ++x) {
        printf("[%d] => ", x);
        for (trav = x; trav != -1 ; trav = D.Nodes[trav].next) {
            printf("%d ", D.Nodes[trav].data);
        }
        printf("\n");
    }
}

void insertDict(Dictionary *D, int elem) {
    int hashValue = hash(elem), *trav;

    for (*trav = hashValue; trav != -1)
}