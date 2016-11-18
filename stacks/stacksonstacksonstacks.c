#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

// S T A C K
struct LL_Cool_Stack {
  int *container;
  int top;
  int capacity;
};

///////////////////

int is_empty(struct LL_Cool_Stack *cool_stack)
{
  if (cool_stack->top == 0 && cool_stack->container[cool_stack->top] == 0) {
    return 1;
  }
  return 0;
};

int is_full(struct LL_Cool_Stack *cool_stack)
{
  if (cool_stack->top >= CAPACITY - 1) {
    return 1;
  }
  return 0;
};

int push(struct LL_Cool_Stack *cool_stack, int new_number)
{
  if (is_full(cool_stack) == 0) {
    cool_stack->top++;
    cool_stack->container[cool_stack->top] = new_number;
    printf("push %d \n", new_number);
    return 1;
  }

  printf("Sorry, cannot push %d to stack; capacity is full. \n", new_number);
  return 0;
};

int peek(struct LL_Cool_Stack *cool_stack)
{
  if (is_empty(cool_stack) == 0) {
    return cool_stack->container[cool_stack->top];
  }

  return 0;
}

int pop(struct LL_Cool_Stack *cool_stack)
{
  int pop_number = peek(cool_stack);
  if (pop_number != 0) {
    cool_stack->top--;
    printf("pop %d \n", pop_number);
    return pop_number;
  }

  printf("Sorry, cannot pop from stack; it is empty. \n");
  return 1;
};

///// M A I N /////
int main (int argc, char *argv[]) {

  struct LL_Cool_Stack cool_stack;
  int arr_container[10];
  int top_num = -1;
  cool_stack.container = arr_container;
  cool_stack.top = top_num;
  cool_stack.capacity = CAPACITY;

  for (int i = 1; i < argc; ++i) {
    push(&cool_stack, atoi(argv[i]));
    printf("%s, ", argv[i]);
  }
  printf("\n");

  pop(&cool_stack);
  pop(&cool_stack);
  pop(&cool_stack);
  pop(&cool_stack);
  pop(&cool_stack);
  pop(&cool_stack);

  for (int i = 0; i <= cool_stack.top; ++i) {
    printf("%d, ", cool_stack.container[i]);
  }
  printf("\n");

  push(&cool_stack, 465);
  push(&cool_stack, 5);
  push(&cool_stack, 18);
  push(&cool_stack, 8443);
  push(&cool_stack, 19);
  push(&cool_stack, 133);
  push(&cool_stack, 6519);
  push(&cool_stack, 12);
  push(&cool_stack, 42);
  push(&cool_stack, 15);
  push(&cool_stack, 139);
  push(&cool_stack, 82);

  for (int i = 0; i <= cool_stack.top; ++i) {
    printf("%d, ", cool_stack.container[i]);
  }
  printf("\n");

  pop(&cool_stack);

  for (int i = 0; i <= cool_stack.top; ++i) {
    printf("%d, ", cool_stack.container[i]);
  }
  printf("\n");
  printf("\n");

  return 0;
}