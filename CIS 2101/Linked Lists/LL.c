#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *link;
} Node, *LIST;

void displayList(LIST head) {
  printf("---------------DISPLAY---------------\n");
  LIST trav;
  for(trav = head; trav != NULL; trav = trav->link){
    printf("%d\n", trav->data);
  }
}

void insertFirst(LIST* head, int data) {
  LIST temp = (LIST)malloc(sizeof(struct node));
  temp->data = data;
  temp->link = *head;
  *head = temp;
}

void insertLast(LIST* head, int data) {
  LIST* trav;
  LIST temp = (LIST)malloc(sizeof(struct node));
  temp->data = data;

  if(*head == NULL) {
    temp->link = *head;
    *head = temp;
  } else {
    for(trav = head; *trav != NULL; trav = &(*trav)->link){}
    *trav = temp;
    temp->link = NULL;
  }
}

void insertAtPos(LIST* head, int data, int index){
  LIST* trav;
  LIST temp = (LIST)malloc(sizeof(struct node));
  temp->data = data;
  int x;

  if(temp != NULL){
    if(index == 0 ){
      temp->link = *head;
      *head = temp;
    } else {
      for(trav = head, x = 1; *trav != NULL && x < index; trav = &(*trav)->link, x++){}
      temp->link = *trav;
      *trav = temp;
    }
  }
}

void insertSorted(LIST* head, int data) {
  LIST* trav;
  LIST temp = (LIST)malloc(sizeof(struct node));
  temp->data = data;

  for(trav = head; trav != NULL && data >= (*trav)->data; trav = &(*trav)->link){}

  temp->link = *trav;
  *trav = temp;
}

void deleteFirst(LIST* head){
  LIST temp = *head;
  *head = (*head)->link;
  // printf("------- %d", (*head)->data);

  free(temp);
  // printf("yes");
}

void deleteAtPos(LIST* head, int pos) {
  LIST* trav;
  int x;
  for(trav = head, x = 1; *trav != NULL && x < pos; x++, trav = &(*trav)->link){}
  LIST temp = (*trav)->link;
  (*trav)->link = temp->link;
  free(temp);
}

int search(LIST head, int data){
  LIST trav;
  int x = 1;
  for(trav = head; trav != NULL && trav->data != data; trav = trav->link, x++){}

  return (trav == NULL) ? -1 : x;

}

int main(void)
{
  LIST head = NULL;
  insertFirst(&head, 16);
  insertFirst(&head, 14);
  insertFirst(&head, 13);
  insertFirst(&head, 12);
  insertLast(&head, 69);
  // insertAtPos(&head, 420, 4);
  insertSorted(&head, 42);
  insertSorted(&head, 15);
  displayList(head);
  deleteFirst(&head);
  displayList(head);
  deleteAtPos(&head, 3);
  displayList(head);

  printf("-------------* %d\n", search(head, 12312));
  printf("-------------* %d\n", search(head, 15));
  return 0;
}