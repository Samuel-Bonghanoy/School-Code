#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef enum {FALSE, TRUE} Boolean;

typedef struct Node {
    int data;
    struct Node *link;
}*LIST;

typedef LIST Dictionary[MAX];
typedef int SET[MAX];

int hash(int elem);
void initDict(Dictionary D);
void displayDict(Dictionary D);
void insert(Dictionary D, int elem);
void delete(Dictionary D, int elem);
Boolean isMember(Dictionary D, int elem);

int main()
{
    Dictionary myDic;
    SET mySet = {17, 31, 52, 782, 248, 160, 79, 7, 502, 256};

    //initialize dictionary
    initDict(myDic);
    displayDict(myDic);

    //insert into dictionary
    int x;
    for (x = 0; x != MAX; ++x) {
        insert(myDic, mySet[x]);
    }
    printf("\n\n");
    displayDict(myDic);

    //delete something at the dictionary
    printf("\n\n");
    delete(myDic, 248);
    delete(myDic, 502);
    delete(myDic, 17);
    displayDict(myDic);

    //check for membership
    printf("\n%d ", isMember(myDic, 52));
    printf("%d ", isMember(myDic, 502));
    return 0;
}

int hash(int elem) {
    return elem % MAX;
}

void initDict(Dictionary D) {
    int x;
    for (x = 0; x != MAX; ++x) {
        D[x] = NULL;
    }
}

void displayDict(Dictionary D) {
    int x;

    LIST trav;
    for (x = 0; x != MAX; ++x) {
        printf("[%d] => ", x);
        for (trav = D[x]; trav != NULL; trav = trav->link) {
            printf("%d ", trav->data);
        }
        printf("\n");
    }
}

void insert(Dictionary D, int elem) {
    int hashValue = hash(elem);

    LIST newNode = (LIST)malloc(sizeof(struct Node)), *trav;
    if (newNode != NULL) {
        for (trav = D + hashValue; *trav != NULL && (*trav)->data < elem; trav = &(*trav)->link) {}
        if (*trav == NULL || (*trav)->data != elem) {
            newNode->data = elem;
            newNode->link = *trav;
            *trav = newNode;
        }
    }
}

void delete(Dictionary D, int elem) {
    int hashValue = hash(elem);

    LIST *trav, temp;
    for (trav = D + hashValue; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link) {}
    if (*trav != NULL && (*trav)->data) {
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

Boolean isMember(Dictionary D, int elem) {
    int hashValue = hash(elem);

    LIST trav;
    for (trav = D[hashValue]; trav != NULL && trav->data != elem; trav = trav->link) {}
    return (trav == NULL) ? FALSE : TRUE;
}