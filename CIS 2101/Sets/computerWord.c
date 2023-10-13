#include <stdio.h>
#include <math.h>

typedef enum {FALSE, TRUE} Boolean;

typedef unsigned char SET;

void initSet(SET *A);
void displayBits(SET A);
void displayElem(SET A);
void displayIndices(SET A);
void insertElem(SET *A, int elem);
void deleteElem(SET *A, int elem);
Boolean isMember(SET A, int elem);

SET unionSet(SET A, SET B);
SET intersectionSet(SET A, SET B);
SET differenceSet(SET A, SET B);
Boolean isDisjoint(SET A, SET B);
Boolean isSubset(SET A, SET B);

int main()
{
    SET mySet;
    initSet(&mySet);

    //display initial
    displayBits(mySet);
    displayElem(mySet);
    displayIndices(mySet);

    //insert elements into my set
    insertElem(&mySet, 2);
    insertElem(&mySet, 6);

    //display updated set
    displayBits(mySet);
    displayElem(mySet);
    displayIndices(mySet);
    return 0;
}

void initSet(SET *A) {
    *A = 0;
}
void displayBits(SET A) {
    printf("bits: ");
    SET mask;
    for (mask = 1 << ((sizeof(SET)*8)-1); mask != 0; mask >>= 1) {
        printf((mask&A) != 0 ? "1" : "0");
    }
    printf("\n");
}

void displayElem(SET A) {
    printf("elem: ");
    int x;
    for (x = 0; A != 0; A >>= 1, ++x) {
        if ((A&1) != 0) {
            printf("[%d]", x);
        }
    }
    printf("\n");
}

void displayIndices(SET A) {
    int x;
    for (x = 0; A != 0; A >>= 1, ++x) {
        if ((A&1) != 0) {
            printf("[%.0f]", pow(2, x));
        }
    }
    printf("\n");
}

void insertElem(SET *A, int elem) {
    *A = (*A)|(1 << elem);
}

void deleteElem(SET *A, int elem) {
    *A = (*A)&~(1 << elem);
}

Boolean isMember(SET A, int elem) {
    return (1 & (A >> elem)) != 0 ? TRUE : FALSE;
}

SET unionSet(SET A, SET B) {
    return A | B;
}

SET intersectionSet(SET A, SET B) {
    return A & B;
}

SET differenceSet(SET A, SET B) {
    return A & ~B;
}

Boolean isDisjointSet(SET A, SET B) {
    return (A | B) == 0 ? TRUE : FALSE;
}

Boolean isSubset(SET A, SET B) {
    return (A | B) == A ? TRUE : FALSE;
}