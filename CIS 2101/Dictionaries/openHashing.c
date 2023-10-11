#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef enum {FALSE, TRUE} Boolean;

typedef struct Node {
    int data;
    struct Node *link;
}*LIST;

typedef LIST Dictionary[MAX];

void initDic(Dictionary *D);
int hash(int num);
Boolean isMember(Dictionary D, int elem);
void displayDic(Dictionary D);
Boolean insertElem(Dictionary *D, int elem);
Boolean deleteElem(Dictionary *D, int elem);

int main()
{
    Dictionary myDic;

    //initialize dictionary
    initDic(&myDic);

    insertElem(&myDic, 34);
    insertElem(&myDic, 7);
    insertElem(&myDic, 3);
    insertElem(&myDic, 1);
    insertElem(&myDic, 27);
    insertElem(&myDic, 37);
    displayDic(myDic);

    deleteElem(&myDic, 7);
    displayDic(myDic);
    return 0;
}

void initDic(Dictionary *D) {
    int x;
    for (x = 0; x != MAX; ++x) {
        (*D)[x] = NULL;
    }
}

int hash(int num) {
    return num % MAX;
}

Boolean isMember(Dictionary D, int elem) {
    int hashValue = hash(elem);

    LIST trav;
    for (trav = D[hashValue]; trav != NULL && trav->data != elem; trav = trav->link) {}
    return trav == NULL ? FALSE : TRUE;
}

void displayDic(Dictionary D) {
    LIST trav;

    int x;
    for (x = 0; x != MAX; ++x) {
        printf("[%d] => ", x);
        for (trav = D[x]; trav != NULL; trav = trav->link) {
            printf("%d ", trav->data);
        }
        printf("\n");
    }
}

Boolean insertElem(Dictionary *D, int elem) {
    int hashValue = hash(elem), retVal = FALSE;

    if (isMember(*D, elem) == FALSE) {
        LIST newNode = (LIST)malloc(sizeof(struct Node));
        if (newNode != NULL) {
            newNode->data = elem;
            newNode->link = (*D)[hashValue];
            (*D)[hashValue] = newNode;
            retVal = TRUE;
        }
    }
    return retVal;
}

Boolean deleteElem(Dictionary *D, int elem) {
    int hashValue = hash(elem), retVal = FALSE;

    if (isMember(*D, elem) == TRUE) {
        LIST *trav, temp;
        for (trav = &((*D)[hashValue]); *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link) {}
        temp = *trav;
        *trav = temp->link;
        free(temp);
        retVal = TRUE;
    }
    return retVal;
}