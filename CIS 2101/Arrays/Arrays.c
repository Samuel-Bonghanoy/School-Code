#include <stdio.h>
#include <stdlib.h>
#define MAX 15

void initialize(int arr[], int* count){
  int x;
  printf("yes");
  for(x = 0; x < *count; x++){
    arr[x] = 0;
    printf("%d", arr[x]);
  }

  *count = 0;
}

void display(int arr[], int count){
  int x; 
  for(x = 0; x < count; x++) printf("%d ", arr[x]);
}


int searchElem(int arr[], int count, int elem){
  int x;
  for(x = 0; x < count && arr[x] != elem; x++){}

  return (arr[x] == elem) ? arr[x] : -1;
}

int insertLast(int arr[], int* count, int elem){
  if(*count != MAX){
    arr[*count++] = elem; 
  }
}

int insertFirst(int arr[], int* count, int elem){
  if(*count != MAX){
    int x;
    for(x = *count - 1; x > 0; x--){
      arr[x] = arr[x - 1];
    }

    arr[0] = elem;
  }
}

int insertAtPos(int arr[], int* count, int elem, int pos);
int removeLast(int arr[], int* count);
int removeFirst(int arr[], int* count);
int removeAtPos(int arr[], int* count, int pos);
int removeElem(int arr[], int* count, int elem);

int getRange(int arr[], int count);
int* getEven(int arr[], int count);
int isSortedAscending(int arr[], int count);
void moveSmallestToFirst(int array[], int count);
void sortArray(int arr[], int count);

int main(void) 
{
  int arr[MAX];
  int count = 0;
  initialize(arr, &count);
  display(arr, count);
  insertLast(arr, &count, 5);
  display(arr, count);
  // printf("start");

  return 0;
}