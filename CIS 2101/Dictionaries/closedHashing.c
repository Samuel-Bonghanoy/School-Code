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
	for(x = 0; x != MAX; x++){
		D[x] = NULL;
	}
}

int isMember(Dictionary D, int elem){
	int hashval = hash(elem);
	LIST trav;
	
	for(trav = D[hashval]; trav != NULL && trav->data != elem; trav = trav->link){}
	
//	printf("%d\n",trav == NULL ? 1 : -1);
	
	return trav == NULL ? 1 : -1;
}

void display(Dictionary D) {
	LIST trav;
	int x;
	
	for(x = 0; x != MAX; x++){
		printf("%d -> ", x);
		for(trav = D[x]; trav != NULL; trav = trav->link){
			printf("%d ", trav->data);
		}
		printf("\n");
	}
}

void insertElem(Dictionary D, int elem){
	int hashval = hash(elem);
//	printf("hashval -> %d\n", hashval);
	LIST *trav;
	
	LIST temp = (LIST)malloc(sizeof(struct node));
	if(temp != NULL){
		for(trav = &(D[hashval]);  *trav != NULL &&  (*trav)->data <= elem; trav = &(*trav)->link){}
		temp->data = elem; 
		temp->link = *trav;
		*trav = temp;
	}
}

void deleteElem(Dictionary D, int elem){
	int hashval = hash(elem);
	LIST *trav;
	
	if(isMember(D, elem) == -1){
		for(trav = &(D[hashval]);  *trav != NULL &&  (*trav)->data != elem; trav = &(*trav)->link){}
		LIST temp = *trav;
		*trav = temp->link;
		free(temp);
	}
}

int main(void) 
{
	Dictionary D;
	initDictionary(D);
	
	int populateArray [] = {48,3,4,28,108,45,38,95,33};
	int x;
	for(x = 0; x < 9; x++){
		insertElem(D, populateArray[x]);
	}
	
	// insertElem(D, 11);
	// insertElem(D, 11);
	insertElem(D, 53);
	display(D);
	
	// printf("After delete: \n");
	
	deleteElem(D, 33);
	// display(D);
	
	// printf("Check is 95 is member:");
	// printf("%d", isMember(D, 95));
	
	
}


