#include <stdio.h> 
#define MAX 10

typedef int LIST;

typedef struct node {
  char data;
  int link;
} Node;

typedef struct {
  Node * nodes;
  LIST avail;
} VirtualHeap;

VirtualHeap init () {
  VirtualHeap heap;
  heap.nodes = calloc(MAX, sizeof(Node));

  int x;
  for(x = MAX - 1; x >= 0; x--) {
    heap.nodes[x].link = x - 1;
  }

  heap.avail = MAX - 1;
  return heap;
}

void displayVH (VirtualHeap VH, LIST L) {
  int trav;
  for(trav = L; trav != -1; trav = VH.nodes[trav].link){
    printf("%c ", VH.nodes[trav].data);
  }
  printf("\n");
}

int alloc(VirtualHeap *VH) {
  int retval = -1;

  if(VH->avail != -1) {
    retval = VH->avail;
    VH->avail = VH->nodes[VH->avail].link;
  }

  return retval;
}

void insertFirstVH (VirtualHeap *VH, LIST *L, char elem){
  int index = alloc(VH);

  if(index != -1) {
    VH->nodes[index].data = elem;
    VH->nodes[index].link = *L;
    *L = index;
  }
}