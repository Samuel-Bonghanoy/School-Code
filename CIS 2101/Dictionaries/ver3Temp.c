#include <ctype.h>
#include <stdio.h>
#define MAX 10
#define EMPTY '!'
#define DELETED '@'

typedef enum { FALSE, TRUE } Boolean;

typedef struct {
  char data;
  int next;
} nodeType;

typedef struct {
  nodeType Nodes[MAX];
  int avail;
} Dictionary;

void initDic(Dictionary *D);
int hash(char input);
int allocSpace(Dictionary *D);
void displayDic(Dictionary D);
// Boolean isMember(Dictionary D, char elem);
void insert(Dictionary *D, char elem);
void delete(Dictionary *D, char elem);

int main() {
  Dictionary myDic;

  initDic(&myDic);
  displayDic(myDic);

  printf("\n");
  insert(&myDic, 'A');
  insert(&myDic, 'B');
  insert(&myDic, 'E');
  insert(&myDic, 'C');
  insert(&myDic, 'D');
  insert(&myDic, 'A');
  insert(&myDic, 'A');
  insert(&myDic, 'A');
  insert(&myDic, 'A');
  // printf("%c", myDic.Nodes[myDic.Nodes[2].next].data);
  // printf("%d", myDic.Nodes[myDic.avail].next);
  displayDic(myDic);

  return 0;
}

void initDic(Dictionary *D) {
  int x;
  for (x = 0; x != MAX / 2; ++x) {
    D->Nodes[x].data = EMPTY;
    D->Nodes[x].next = -1;
  }

  for (; x != MAX - 1; ++x) {
    D->Nodes[x].next = x + 1;
  }
  D->Nodes[MAX - 1].next = -1;
  D->avail = MAX / 2;
}

int hash(char input) {
  int ret;
  switch (input) {
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
    ret = (toupper(input) - 'A');
    break;
  }
  return ret;
}

int allocSpace(Dictionary *D) {
  int retVal = D->avail;

  if (D->avail != -1) {
    D->avail = D->Nodes[D->avail].next;
  }
  return retVal;
}

void displayDic(Dictionary D) {
  int x, trav;
  for (x = 0; x != MAX / 2; ++x) {
    printf("[%d] => ", x);
    trav = x;

    do {
      printf("%c ", D.Nodes[trav].data);
      trav = D.Nodes[trav].next;
    } while (trav != -1);
    printf("\n");
  }
}

void insert(Dictionary *D, char elem) {
  // int hashValue = hash(elem);

  // if (D->Nodes[hashValue].data == EMPTY) {
  //     D->Nodes[hashValue].data = elem;
  // } else {
  //     int newNode = allocSpace(D);
  //     D->Nodes[newNode].data = elem;
  //     D->Nodes[newNode].next = -1;

  //     if (D->Nodes[hashValue].next == -1) {
  //         D->Nodes[newNode].next = -1;
  //         D->Nodes[hashValue].next = newNode;
  //     } else {
  //         int trav;
  //         for (trav = D->Nodes[hashValue].next; trav != -1; trav =
  //         D->Nodes[trav].next) {} D->Nodes[newNode].next = -1;
  //         D->Nodes[trav].next = newNode;
  //     }
  // }

  int hashValue = hash(elem);

  if (D->Nodes[hashValue].data == EMPTY) {
    D->Nodes[hashValue].data = elem;
  } else {
    int *trav = &(D->Nodes[hashValue].next), newNode = allocSpace(D);

    for (; *trav != -1; trav = &(D->Nodes[*trav].next)) {
    }
    D->Nodes[newNode].data = elem;
    D->Nodes[newNode].next = *trav;
    *trav = newNode;
  }
}

void delete(Dictionary *D, char elem) {}