// implementation of a Stack employing
// a Linked List as a 'container' in C
// author: @vipyne

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
    return 1;
  }
  return 0;
};

int push(struct LL_Cool_Stack *cool_stack, int new_number)
{
  if (is_full(cool_stack) == 0) {
    // alternatively could `calloc` here to avoid if statement
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->number = new_number;
    if ( !(cool_stack->count == 0) ) {
      new_node->next = cool_stack->current_top;
    } else {
      // initialize first node with NULL pointer
      new_node->next = (struct Node *)0x989000;
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
  curr_top.number = 0;
  curr_top.next = NULL;

  struct LL_Cool_Stack cool_stack;

  cool_stack.current_top = &curr_top;
  cool_stack.capacity = CAPACITY;
  cool_stack.count = 0;

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

  printf("Current stack from top to bottom: (empty)\n");
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

  printf("Current stack from top to bottom: \n");
  // using malloc here not necessary, just a variation to
  // illustrate another way of doing things
  struct Node *malloced_temp_placeholder = (struct Node *)malloc(sizeof(struct Node));
  malloced_temp_placeholder = cool_stack.current_top;
  while(malloced_temp_placeholder->next != NULL) {
    printf("%d, ", malloced_temp_placeholder->number);
    malloced_temp_placeholder = malloced_temp_placeholder->next;
  }
  // print last number outside loop
  // because it's next pointer is
  // (and should be) NULL
  printf("%d ", malloced_temp_placeholder->number);
  free(malloced_temp_placeholder);

  printf("\n");
  printf("\n");

  pop(&cool_stack);

  printf("Current stack from top to bottom: \n");
  temp_placeholder = cool_stack.current_top;
  while (temp_placeholder->next != NULL) {
    printf("%d, ", temp_placeholder->number);
    temp_placeholder = temp_placeholder->next;
  }
  printf("%d ", temp_placeholder->number);

  printf("\n");
  printf("\n");

  return 0;
}

///// O U T P U T /////

// vipyne $ gcc llcoolstack.c -o llcoolstack.exe
// vipyne $ ./llcoolstack.exe 2 6 7 657
// push 2
// 2, push 6
// 6, push 7
// 7, push 657
// 657,
// 657, 7, 6, 2,

// pop 657
// pop 7
// pop 6
// pop 2
// Sorry, cannot pop from the stack; it is empty.
// Sorry, cannot pop from the stack; it is empty.
// Sorry, cannot pop from the stack; it is empty.
// Sorry, cannot pop from the stack; it is empty.
// Current stack from top to bottom:

// push 465
// push 5
// push 18
// push 8443
// push 19
// push 133
// push 6519
// push 12
// push 42
// push 15
// Sorry, cannot push 139 to stack; capacity is full.
// Sorry, cannot push 82 to stack; capacity is full.
// Current stack from top to bottom:
// 15, 42, 12, 6519, 133, 19, 8443, 18, 5, 465

// pop 15
// Current stack from top to bottom:
// 42, 12, 6519, 133, 19, 8443, 18, 5, 465