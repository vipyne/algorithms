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
  return new_node;
}

// as if just linked list
void add_node(struct Node* parent, struct Node* new_node)
{
  if (parent->data < new_node->data) {
    if (parent->greaterChild > 0) {
      add_node(parent->greaterChild, new_node);
    } else {
      new_node->parent = parent;
      parent->greaterChild = new_node;
    }
   } else {
    if (parent->lesserChild > 0) {
      add_node(parent->lesserChild, new_node);
    } else {
      new_node->parent = parent;
      parent->lesserChild = new_node;
    }
  }
}

// void print_char (struct Node *tree_root, int side)
// {
//   struct Node* preorder_node = (struct Node*)calloc(1, sizeof(struct Node));
//   if (side == 1) {
//     // left side of tree
//     preorder_node = tree_root->lesserChild;
//     printf("%c", preorder_node->data);
//     if (preorder_node && ((preorder_node->lesserChild != NULL) || preorder_node->parent == NULL)) {
//       print_char (preorder_node, 1);
//     }
//   } else {
//     // right side of tree
//     preorder_node = tree_root->greaterChild;
//     printf("%c", preorder_node->data);
//       if (preorder_node && ((preorder_node->greaterChild != NULL) || preorder_node->parent == NULL)) {
//       print_char (preorder_node, 0);
//     }
//   }
//   // if (preorder_node) {
//   // }
//   // printf("%c", tree_root->data);
// }

void print_char (struct Node *tree_root)
{
  printf("%c", tree_root->data);
  if (tree_root->lesserChild != NULL) {
    print_char (tree_root->lesserChild);
  }
  if (tree_root->greaterChild != NULL) {
    print_char (tree_root->greaterChild);
  }
}



int main(void)
{
  char string[] = "bodras$";
  struct Node word_root;
  word_root.data = string[0];
  // word_root.char_count = 1;
  word_root.parent = NULL;
  word_root.lesserChild = NULL;
  word_root.greaterChild = NULL;
  // word_root.leftMostChild = NULL;
  // word_root.rightSibling = NULL;

  struct Node* temp_node = &word_root;
  temp_node->data = word_root.data;
  // TODO: deal with duplicate chars
  for (int i = 1; string[i] != '\0'; ++i) {
    struct Node* new_node = create_node(string[i]);
    add_node(&word_root, new_node);
  }

  // // print preorder - ROOT, LEFT, RIGHT
  // for (int i = 0; string[i] != '\0'; ++i) {
  //   printf("%c", string[i]);
  // }
  // printf("\n");
  // struct Node* preorder_node = &word_root;
  // while (preorder_node->lesserChild != NULL) {
  //   preorder_node = preorder_node->lesserChild;
  // }

  print_char(&word_root);
  printf("\n");



  // print postorder - LEFT, RIGHT, ROOT
  // ...

  printf("done\n");

  return 0;
}