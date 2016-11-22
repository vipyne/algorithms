#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 10

struct LL_Cool_Stack;
struct Node;

// S T A C K
struct LL_Cool_Stack {
  struct Node *current_top;
  int count;
  int capacity;
};

// N O D E
struct Node {
  int number;
  struct Node *next;
};

///////////////////////////////

int is_empty(struct LL_Cool_Stack *cool_stack)
{
  if (cool_stack->count <= 0) {
    return 1;
  }
  return 0;
};

int is_full(struct LL_Cool_Stack *cool_stack)
{
  if (cool_stack->count >= CAPACITY) {
  }
  return 0;
};

int push(struct LL_Cool_Stack *cool_stack, int new_number)
{
  if (is_full(cool_stack) == 0) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->number = new_number;
    if ( !(cool_stack->count == 0) ) {
      new_node->next = cool_stack->current_top;
    } else {
      new_node->next = NULL;
    }
    cool_stack->current_top = new_node;
    cool_stack->count++;
    printf("push %d \n", new_number);
    return 0;
  }

  printf("Sorry, cannot push %d to stack; capacity is full. \n", new_number);
  return 1;
};

int peek(struct LL_Cool_Stack *cool_stack)
{
  if (!is_empty(cool_stack)) {
    return cool_stack->current_top->number;
  }

  return 0;
}

int pop(struct LL_Cool_Stack *cool_stack)
{
  if (!is_empty(cool_stack)) {
    int top_number = cool_stack->current_top->number;
    cool_stack->current_top = cool_stack->current_top->next;
    cool_stack->count--;
    printf("pop %d \n", top_number);
    return top_number;
  }

  printf("Sorry, cannot pop from the stack; it is empty. \n");
  return 1;
};

///// M A I N /////
int main (int argc, char *argv[]) {

  struct Node curr_top;
  curr_top.number = 900;
  curr_top.next = NULL;

  struct LL_Cool_Stack cool_stack;

  cool_stack.current_top = &curr_top;
  cool_stack.capacity = CAPACITY;
  cool_stack.count = 1;

  for (int i = 1; i < argc; ++i) {
    push(&cool_stack, atoi(argv[i]));
    printf("%s, ", argv[i]);
  }
  printf("\n");

  struct Node *temp_placeholder;
  temp_placeholder = cool_stack.current_top;

  while (temp_placeholder != NULL) {
    printf("%d, ", temp_placeholder->number);
    temp_placeholder = temp_placeholder->next;
  }
  printf("\n");
  printf("\n");

  pop(&cool_stack);
  pop(&cool_stack);
  pop(&cool_stack);
  pop(&cool_stack);
  pop(&cool_stack);
  pop(&cool_stack);
  pop(&cool_stack);
  pop(&cool_stack);

  temp_placeholder = cool_stack.current_top;
  while (temp_placeholder != NULL) {
    printf("%d, ", temp_placeholder->number);
    temp_placeholder = temp_placeholder->next;
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

  struct Node *t2emp_placeholder = (struct Node *)malloc(sizeof(struct Node));
  t2emp_placeholder = cool_stack.current_top;
  while(t2emp_placeholder != NULL && t2emp_placeholder->next != NULL) {
    t2emp_placeholder = t2emp_placeholder->next;
  }
  free(t2emp_placeholder);

  printf("\n");
  printf("\n");

  pop(&cool_stack);

  temp_placeholder = cool_stack.current_top;
  while (temp_placeholder != NULL && temp_placeholder->next != NULL) {
    printf("%d, ", temp_placeholder->number);
    temp_placeholder = temp_placeholder->next;
  }

  printf("\n");
  printf("\n");

  return 0;
}