#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
  char data;
  struct node *next;
} Node, *LinkedList;

typedef LinkedList *HashMap; 

LinkedList *init(void);
void printLinkedList(LinkedList *L);
void insertLast(LinkedList *L, char newData);

int main(void) {
  LinkedList L = NULL;
  printLinkedList(&L);

  insertLast(&L, 'Z');
  printLinkedList(&L);

  HashMap map = init();
  for (int i = 0; i < MAX; i++) {
    printLinkedList(&map[i]);
  }
}

HashMap init(void) {
  HashMap newHashMap = malloc(sizeof(LinkedList) * MAX);

  for (int i = 0; i < MAX; i++) {
    newHashMap[i] = NULL;
  }

  return newHashMap;
}

void printLinkedList(LinkedList *L) {
  for (LinkedList *trav = L; *trav != NULL; trav = &(*trav)->next) {
    printf("[%p](%c)->", *trav, (*trav)->data);
  }
  printf("[NULL]\n");
}

void insertLast(LinkedList *L, char newData) {
  LinkedList *trav;
  for (trav = L; *trav != NULL; trav = &(*trav)->next) {}

  Node *newNode = malloc(sizeof(Node));
  newNode->data = newData;
  newNode->next = NULL;

  *trav = newNode;
}