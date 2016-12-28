#include <stdio.h>
#include <stdlib.h>

struct Node {
  unsigned char data;
  unsigned short int char_count;

  struct Node* parent;
  struct Node* lesserChild;
  struct Node* greaterChild;
};

struct Node* create_node(char data)
{
  struct Node* new_node = (struct Node*)calloc(1, sizeof(struct Node));
  new_node->data = data;
  new_node->char_count = 1;
  return new_node;
}

void add_node(struct Node* parent, struct Node* new_node)
{
  if (parent->data < new_node->data) {
    if (parent->greaterChild > 0) {
      add_node(parent->greaterChild, new_node);
    } else {
      new_node->parent = parent;
      parent->greaterChild = new_node;
    }
  } else if (parent->data > new_node->data) {
    if (parent->lesserChild > 0) {
      add_node(parent->lesserChild, new_node);
    } else {
      new_node->parent = parent;
      parent->lesserChild = new_node;
    }
  } else {
    parent->char_count++;
  }
}

void print_preorder (struct Node *tree_root)
{
  printf("%c", tree_root->data);
  // printf("%c:%d - ", tree_root->data, tree_root->char_count);
  if (tree_root->lesserChild != NULL) {
    print_preorder (tree_root->lesserChild);
  }
  if (tree_root->greaterChild != NULL) {
    print_preorder (tree_root->greaterChild);
  }
}

void print_postorder (struct Node *tree_root)
{
  if (tree_root->lesserChild != NULL) {
    print_postorder (tree_root->lesserChild);
  }
  if (tree_root->greaterChild != NULL) {
    print_postorder (tree_root->greaterChild);
  }
  printf("%c", tree_root->data);
  // printf("%c:%d - ", tree_root->data, tree_root->char_count);
}

int main(void)
{
  char string[] = "badros$";
  struct Node word_root;
  word_root.data = string[0];
  word_root.char_count = 544;
  word_root.parent = NULL;
  word_root.lesserChild = NULL;
  word_root.greaterChild = NULL;

  struct Node* temp_node = &word_root;
  temp_node->data = word_root.data;
  for (int i = 1; string[i] != '\0'; ++i) {
    struct Node* new_node = create_node(string[i]);
    add_node(&word_root, new_node);
  }

  printf("--- preorder ---\n");
  print_preorder(&word_root);
  printf("    \n --- ---");
  printf("\n");

  printf("--- postorder ---\n");
  print_postorder(&word_root);
  printf("    \n --- ---");
  printf("\n");

  return 0;
}