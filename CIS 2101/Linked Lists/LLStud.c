#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char FN[24], LN[16], MI;   //first name, last name, middle initial
}Nametype;

typedef struct {
   char ID[10];
   Nametype name;
   char course[8];
   int yearLevel;
}studrec;

typedef struct node {
    studrec stud;
    struct node *link;
}*LIST;   //Definition of the list

void displayList(LIST head);
void displayRecord(studrec elem);
void insertFirst(LIST *head, studrec elem); 
void insertSorted(LIST *head, studrec elem);
int deleteAll(LIST *head, char course[]);
studrec findStudent(LIST *head, char id[]);

int main()
{
	LIST head = NULL;

  studrec arr[5] = {{"20103261", {"Bonghanoy", "Samuel", 'S'}, "BS-CS", 1}, 
  {"20103262", {"Sanchez", "Bryan", 'M'}, "BS-CS", 2}, 
  {"20103243", {"De Jesus", "Christian", 'L'}, "BS-CS", 3},
  {"20104000", {"Buenavista", "Estelito", 'Y'}, "BS-CS", 1},
  {"20103999", {"Lim", "Reece", 'R'}, "BS-CS", 2}};

  int i;
  for(i = 0; i < 5; i++) insertSorted(&head, arr[i]);

  displayList(head);
  printf("\nThe results of search function:\n");
  studrec retVal = findStudent(&head, "20103262");
  displayRecord(retVal);
}

void displayList(LIST head)
{
	while (head != NULL){
	  printf("%-25s",head->stud.ID);
	  printf("%-25s",head->stud.name.FN);
	  printf("%-25s",head->stud.name.LN);
	  printf("%-5c",head->stud.name.MI);
	  printf("%-10s ",head->stud.course);
	  printf("%-10d\n",head->stud.yearLevel);
	  head = head->link;
	}
}

void displayRecord(studrec elem)
{
	printf("%-25s",elem.ID);
	printf("%-25s",elem.name.FN);
	printf("%-25s",elem.name.LN);
	printf("%-5c",elem.name.MI);
	printf("%-10s ",elem.course);
	printf("%-10d\n",elem.yearLevel);
}


void insertFirst(LIST *head, studrec elem)
{
	LIST temp = (LIST)malloc(sizeof(struct node));
	if (temp != NULL){
		temp->stud = elem;
		temp->link = *head;
		*head = temp;
	} 
}

studrec findStudent(LIST *head, char id[])
{
  LIST *trav = head;
  for(; strcmp((*trav)->stud.ID, id) != 0 && (*trav) != NULL; (*trav) = (*trav)->link) {}
  studrec dummy = {"XXXXXX", {"Dummy", "Student", 'X'}, "BS-CS", 1};

  return *trav != NULL ? (*trav)->stud : dummy;
}

void insertSorted(LIST *head, studrec elem)
{
  LIST temp = (LIST) malloc(sizeof(struct node));
  temp->stud = elem;
  
  if (*head == NULL) {
    *head = temp;
    temp->link = NULL;

  } else if (strcmp(temp->stud.ID, (*head)->stud.ID) < 0) {
    temp->link = *head;
    *head = temp;

  } else {
    LIST trav = *head;
    LIST prev = NULL;

    for(; trav != NULL && strcmp(temp->stud.ID, trav->stud.ID) >= 0; prev = trav, trav = trav->link) {}

    temp->link = trav;
    prev->link = temp;
  } 
}

int deleteAll(LIST *head, char course[]) {
  int count = 0;
  LIST trav = *head;
  LIST tempHead = *head;
  LIST prev = NULL;

  for(; trav != NULL; prev = trav, trav = trav->link) {
    if (strcmp(trav->stud.course, course) == 0) {
      if (trav == tempHead) {
        *head = trav->link;
        free(trav);
        trav = *head;
        count++;
      } else {
        prev->link = trav->link;
        free(trav);
        trav = prev->link;
        count++;
      }
    } 
  }
    return count;
}