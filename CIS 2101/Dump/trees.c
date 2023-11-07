

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define ROOT -1
#define DNS -2

typedef int TREE[MAX];
typedef int node;
typedef int label;

void Display(TREE T);
node Parent(node N, TREE T);
node Root(TREE T);
void Initialize(TREE T, int values[]);
void MakeNULL(TREE T);
label Label(node N, TREE T);


int main()
{
    TREE myTree;
    int myArr[] = {5, 6, 5, 6, 1, ROOT, 5, 1, 2, DNS};

   
    Initialize(myTree, myArr);
    Display(myTree);

  
    printf("%d\n", Parent(4, myTree));
    printf("%d\n", Parent(5, myTree));
    printf("%d\n", Parent(9, myTree));
    
    printf("\n%d\n", Label(4, myTree));
    printf("%d\n", Label(5, myTree));
    printf("%d\n\n", Label(9, myTree));

    MakeNULL(myTree);
    Display(myTree);
    return 0;
}

void Display(TREE T) {
    int x;
    for (x = 0; x < MAX; ++x) {
        printf("[%d] => ", x);
        if (T[x] == ROOT) {
            printf("ROOT");
        } else if (T[x] == DNS) {
            printf("DNS");
        } else {
            printf("%d", T[x]);
        }
        printf("\n");
    }
    printf("\n");
}

node Parent(node N, TREE T) {
    return T[N] != DNS && T[N] != ROOT ? T[N] : DNS;
}

label Label(node N, TREE T) {
    return T[N];
}

node Root(TREE T) {
    int x;
    for (x = 0; x < MAX && T[x] != ROOT; ++x) {}
    return x == MAX ? DNS : x;
}

void Initialize(TREE T, int values[]) {
    int x;
    for (x = 0; x < MAX; ++x) {
        T[x] = values[x];
    }
}

void MakeNULL(TREE T) {
    int x;
    for (x = 0; x < MAX; ++x) {
        T[x] = DNS;
    }
}

