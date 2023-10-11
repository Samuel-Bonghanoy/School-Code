#include <stdio.h>
#include <ctype.h>
#define MAX 4
#define EMPTY '!'
#define DELETED '@'

typedef enum {FALSE, TRUE} Boolean;

typedef char Dictionary[MAX];

void initDic(Dictionary D) {
  int x;
  for(x = 0; x < MAX; x++){
    D[x] =  EMPTY;
  }
}

int hash(char input) {
  int ret = (toupper(input) - 'A');
  return ret; 
}

void displayDic(Dictionary D) {
  int x;

  for(x = 0; x < MAX; x++){
    printf("[%d] => %c ", x, D[x]);
  }

  printf("\n");
}

void insert(Dictionary D, char elem) {
  int hashval = hash(elem);
  int x;
  
  if(D[hashval] == EMPTY){
    D[hashval] = elem;
  } else {
    for(x = 0; x < MAX && D[hashval] != EMPTY && D[hashval] != DELETED; hashval = (hashval + 1) % MAX, x++){}
    if(D[hashval] == EMPTY || D[hashval] == DELETED){
      D[hashval] = elem;
    }
  }
}

Boolean isMember(Dictionary D, char elem) {
  int x;
  int hashval = hash(elem);

  for(x = 0; x != MAX && D[hashval] != elem; hashval = (hashval + 1) % MAX, x++){}

  return x == MAX ? FALSE : TRUE;
}

void delete(Dictionary D, char elem) {
  int x, hashval = hash(elem);

  for(x = 0; x != MAX && D[hashval] != elem; x++, hashval = (hashval + 1) % MAX){}

  if(x != MAX) D[hashval] = DELETED;
}

int main()
{
    
}