#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
	int data; 
	struct node *link;
}*LIST;

typedef LIST Dictionary [MAX];

int hash(int n){
	return n % 10;
}

void initDictionary(Dictionary D){
  int x;
  for(x = 0; x < MAX; x++){
    D[x] = NULL;
  }
}

int isMember(Dictionary D, int elem){
	int hashval = hash(elem);
  LIST trav;
  for(trav = D[hashval]; trav != NULL && trav->data != elem; trav = trav->link){}

  return trav == NULL ? 1 : -1;
}

void display(Dictionary D) {
	int x;
  LIST trav;
  for(x = 0; x < MAX; x++){
    printf("%d -> ", x);
    for(trav = D[x]; trav != NULL; trav = trav->link){
      printf("%d -> ", D[x]->data);
    }
    printf("\n");
  }
}

void insertElem(Dictionary D, int elem){
  int hashval = hash(elem);
  LIST *trav;

  LIST temp = (LIST)malloc(sizeof(struct node));
  for(trav = &(D[hashval]); trav != NULL && (*trav)->data <= elem; trav = &(*trav)->link){}
  temp->data = elem; 
  temp->link = *trav;
  *trav = temp;
  
}

void deleteElem(Dictionary D, int elem){
  int hashval = hash(elem);
  LIST *trav, temp;
  

  if(isMember(D, elem)){
    for(trav = &(D[hashval]); trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}
    temp = *trav;
    *trav = temp->link;
    free(temp);
  }
}

int main(void) 
{
	
}


