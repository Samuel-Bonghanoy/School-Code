#include <stdio.h>
#include <ctype.h>
#define MAX 10
#define EMPTY '!'
#define DELETED '@'

typedef enum {FALSE, TRUE} Boolean;

typedef struct {
    char data;
    int next;
}nodeType;

typedef struct {
    nodeType Dictionary[MAX];
    int avail;
}virtualHeap;

int allocSpace(virtualHeap *VH);
void initHeap(virtualHeap *VH);
int hash(char input);
void displayDict(virtualHeap VH);
void insert(virtualHeap *VH, char elem);

int main()
{
    virtualHeap myHeap;

    initHeap(&myHeap);
    displayDict(myHeap);

    printf("\n");
    insert(&myHeap, 'A');
    insert(&myHeap, 'A');
    insert(&myHeap, 'B');
    insert(&myHeap, 'C');
    insert(&myHeap, 'E');
    displayDict(myHeap);
    return 0;
}

int allocSpace(virtualHeap *VH) {
    int retVal = VH->avail;

    if (VH->avail != -1) {
        VH->avail = VH->Dictionary[VH->avail].next;
    }
    return retVal;
}

void initHeap(virtualHeap *VH) {
    int x;
    for (x = 0; x != MAX; ++x) {
        VH->Dictionary[x].next = -1;
        if (x > MAX / 2) {
            VH->Dictionary[x].next = x + 1;
        } else {
            VH->Dictionary[x].data = EMPTY;
        }
    }
    VH->Dictionary[MAX - 1].next = -1;
    VH->avail = MAX / 2;
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

void displayDict(virtualHeap VH) {
    int x, trav;
    
    for (x = 0; x != MAX / 2; ++x) {
        printf("[%d] => ", x);
        for (trav = x; VH.Dictionary[trav].next != -1 ^ VH.Dictionary[trav].data != EMPTY; trav = VH.Dictionary[trav].next) {
            printf("%c", VH.Dictionary[trav].data);
        }
        printf("\n");
    }
}

void insert(virtualHeap *VH, char elem) {
    int hashValue = hash(elem);
    printf("%d", hashValue);

    if (VH->Dictionary[hashValue].data == EMPTY || VH->Dictionary[hashValue].data == DELETED) {
        VH->Dictionary[hashValue].data = elem;
    } else {
        int trav;
        for (trav = VH->Dictionary[hashValue].next; trav != -1; trav = VH->Dictionary[trav].next) {}
        int newNode = allocSpace(VH);
        

        if (newNode != -1) {
            VH->Dictionary[newNode].data = elem;
            VH->Dictionary[newNode].next = -1;
            VH->Dictionary[trav].next = newNode;
        } 
    }
}