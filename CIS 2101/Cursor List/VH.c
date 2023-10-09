#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef int LIST;

typedef struct node {
  char data;
  int link;
} Node;

typedef struct {
  Node *nodes;
  LIST avail;
 } VirtualHeap;

VirtualHeap init() {
  VirtualHeap VH;
  VH.nodes = (Node *)malloc(sizeof(Node));

  int x;
  for(x = MAX - 1; x >= 0; x++){
    VH.nodes[x].link = x - 1;
  }

  VH.avail = MAX - 1;
  return VH;
}

int alloc(VirtualHeap VH, LIST L)


int main()
{
  LIST L = 
  return 0;
}