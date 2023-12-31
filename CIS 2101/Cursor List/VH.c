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
  int x;

  VirtualHeap VH;

  VH.nodes = (Node *)malloc(sizeof(struct node)) ;

  for(x = MAX - 1; x >= 0; x--){
    VH.nodes[x].link = x - 1;
  }

  VH.avail = MAX - 1;

  return VH;
}

void displayList(VirtualHeap VH, LIST L) {
  int trav;

  for(trav = L; trav != -1; trav = VH.nodes[trav].link) {
    printf("[%d](%c)->", trav, VH.nodes[trav].data);
  }
}

int alloc(VirtualHeap* VH){
  int retval = -1;

  if(VH->avail != -1) {
    retval = VH->avail;
    VH->avail = VH->nodes[VH->avail].link;
  }

  return retval;
}

void insertFirst(VirtualHeap *VH, LIST *L, char elem){
  int index = alloc(VH);

  if(index != -1){
    VH->nodes[index].data = elem;
    VH->nodes[index].link = *L;
    *L = index;
  }
}

void dealloc(VirtualHeap *VH, LIST *L, int index){
  int x, trav;
  
  if(*L != -1){
    for(x = MAX - 1, trav = *L;x > index && VH->nodes[trav].link != -1; x--, trav = VH->nodes[trav].link){}
    VH->nodes[trav].link = VH->nodes[index].link;
    VH->nodes[index].link = VH->avail;
    VH->avail = index;
  }
}

void insertRear(VirtualHeap *VH, LIST *L, char elem){
  int index = alloc(VH), trav;

  if(index != -1) {
    for(trav = *L; VH->nodes[trav].link != -1; trav = VH->nodes[trav].link){}
    VH->nodes[index].data = elem;
    VH->nodes[index].link = VH->nodes[trav].link;
    VH->nodes[trav].link = index;
  }
}

void insertSorted(VirtualHeap *VH, LIST *L, char elem){
  int index = alloc(VH), trav;

  if(index != -1){
    for(trav = *L; trav != -1 && elem > VH->nodes[trav].data; trav = VH->nodes[trav].link){}
    if(trav == *L) {
      VH->nodes[index].data = elem;
      VH->nodes[index].link = *L;
      *L = index;
    } else {
      VH->nodes[index].data = elem;
      VH->nodes[index].link = VH->nodes[trav].link;
      VH->nodes[trav].link = index;
    }
  }
}
  

int main()
{
  VirtualHeap VH = init();
  LIST L = -1;
  
  puts("Avail at the start:");
  displayList(VH, VH.avail); // prints VH->Avail list
  puts("");

  insertFirst(&VH, &L, 'e');
  displayList(VH, L);
  puts("");
  insertFirst(&VH, &L, 'd');
  displayList(VH, L);
  puts("");
  insertFirst(&VH, &L, 'c');
  displayList(VH, L);
  puts("");
  insertFirst(&VH, &L, 'b');
  displayList(VH, L);
  puts("");
  // insertRear(&VH, &L, 'a');
  // displayList(VH, L);
  // puts("");
  insertSorted(&VH, &L, 'f');
  displayList(VH, L);
  puts("");
  // dealloc(&VH,&L, 9);
  // insertFirst(&VH, &L, 'j');
  // displayList(VH, L);
  // printf("%d", L);
  // puts("");
  // insertFirst(&VH, &L, 'c');
  // puts("New List L:");
  // displayList(VH, L); // prints L list
  // puts("Avail:");
  // displayList(VH, VH.avail); // prints VH->Avail list
  // puts("");
  return 0;
}