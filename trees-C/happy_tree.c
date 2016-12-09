#include <stdio.h>
#include <stdlib.h>

struct Node {
  // unsigned short int data;
  char data;
  unsigned int char_count;

  struct Node* parent;
  struct Node* lesserChild;
  struct Node* greaterChild;
  // struct Node* leftMostChild;
  // struct Node* rightSibling;
};


struct Node* create_node(char data)
{
  struct Node* new_node = (struct Node*)calloc(1, sizeof(struct Node));
  new_node->data = data;
  // new_node->parent = NULL;
  // new_node->lesserChild = NULL;
  // new_node->greaterChild = NULL;
  // new_node->leftMostChild = NULL;
  // new_node->rightSibling = NULL;
  return new_node;
}

// as if just linked list
void add_node(struct Node* parent, struct Node* new_node)
{
  // Node letter = (struct Node)malloc(sizeof(struct Node));
  // new_node.char_count = 1;

  if (parent->data < new_node->data) {
    if (parent->greaterChild > 0) {
      add_node(parent->greaterChild, new_node);
    } else {
      new_node->parent = parent;
      parent->greaterChild = new_node;
    }
   } else {
    // if (parent->data < new_node->data) {
    if (parent->lesserChild > 0) {
      add_node(parent->lesserChild, new_node);
    } else {
      new_node->parent = parent;
      parent->lesserChild = new_node;
    }
  }


  // new_node.leftMostChild = NULL;
  // new_node.rightSibling = NULL;
}


int main(void)
{

  char string[] = "bodras$";

  // unsigned int count = 0;
  // // find middle number to be root:
  // for (int i = 0; string[i] != '\0'; ++i) {
  //   ++count;
  // }

  struct Node word_root;
  word_root.data = string[0];
  // word_root.char_count = 1;
  word_root.parent = NULL;
  word_root.lesserChild = NULL;
  word_root.greaterChild = NULL;
  // word_root.leftMostChild = NULL;
  // word_root.rightSibling = NULL;


  // struct Node* temp_node = (struct Node*)calloc(1, sizeof(struct Node*));
  struct Node* temp_node = &word_root;
  temp_node->data = word_root.data;
  // TODO: deal with duplicate chars
  for (int i = 1; string[i] != '\0'; ++i) {
    struct Node* new_node = create_node(string[i]);
    add_node(&word_root, new_node);
    // temp_node = new_node;
    // temp_node->data = new_node->data;
  }


  // print preorder - ROOT, LEFT, RIGHT




  // print postorder - LEFT, RIGHT, ROOT


  printf("nerd\n");


  return 0;
}