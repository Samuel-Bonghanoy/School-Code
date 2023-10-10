#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10 // can change this, it's private

struct Stack
{
  char data[MAX];
  int top;
};

typedef struct Stack *Stack;

Stack init() {
  Stack s = (Stack)malloc(sizeof(struct Stack));
  s->top = -1;
  return s;
}

void pop(Stack s) {
  if(s->top >= 0) s->top--;
}

void push(Stack s, char elem) {
  if(s->top < MAX) {
    s->data[++s->top] = elem;
  }
}

char top(Stack s){
  return (s->top != -1 ? s->data[s->top] : '/0');
}

int isEmpty(Stack s) {
  return s->top == -1 ? 1 : 0;
}

int isFull(Stack s) {
  
}