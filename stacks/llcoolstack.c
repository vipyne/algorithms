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
  // printf("Stack is empty - count %d . \n", cool_stack->count);

  if (cool_stack->count <= 0) {
  printf("inside empty - count %d . \n", cool_stack->count);
    return 1;
  }
  return 0;
};

int is_full(struct LL_Cool_Stack *cool_stack)
{
  // printf("Stack is FULL - count %d . \n", cool_stack->count);
  if (cool_stack->count >= CAPACITY - 1) {
  printf("inside  FULL - count %d . \n", cool_stack->count);
    return 1;
  }
  return 0;
};

int push(struct LL_Cool_Stack *cool_stack, int new_number)
{
  if (is_full(cool_stack) == 0) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->number = new_number;
    if ( !(cool_stack->count == 0) ) {
      printf("inside if \n");
      new_node->next = cool_stack->current_top;
      // cool_stack->current_top->next = new_node;
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
    printf("2345345345-------, ");

  if (!is_empty(cool_stack)) {
    printf("---wefs-ds-df-sdf-dsf-sd-fsd-fsd-fsd---, \n");
    int top_number = cool_stack->current_top->number;
    // struct Node *temp = cool_stack->current_top;
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
    printf("argv::%s, ", argv[i]);
  }
  printf("\n");
    printf("argv:--:count:--: %d\n", cool_stack.count);

  struct Node *temp_placeholder;
  temp_placeholder = cool_stack.current_top;

  while (temp_placeholder != NULL) {
    printf("%d, ", temp_placeholder->number);
    temp_placeholder = temp_placeholder->next;
  }
  printf("\n");
  printf("\n");

    printf("1 after pop op opopo popp count-------------%d, ",cool_stack.count);
  pop(&cool_stack);
    printf("2 after pop op opopo popp count-------------%d, ",cool_stack.count);
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

  temp_placeholder = cool_stack.current_top;
  while (temp_placeholder != NULL && temp_placeholder->next != NULL) {
  printf("blahblah blah blah. \n");
    printf("%d, ", temp_placeholder->number);
    temp_placeholder = temp_placeholder->next;
  }

  printf("\n");
  printf("\n");
  printf("2 2 2 2 2 2 2 2 22 . \n");

  pop(&cool_stack);

  printf("3. \n");

  temp_placeholder = cool_stack.current_top;
  while (temp_placeholder != NULL && temp_placeholder->next != NULL) {
  printf("derp. \n");
    printf("%d, ", temp_placeholder->number);
    temp_placeholder = temp_placeholder->next;
  }

  printf("4444. \n");
  printf("\n");
  printf("\n");

  return 0;
}