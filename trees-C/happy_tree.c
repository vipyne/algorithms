#include <stdio.h>
#include <stdlib.h>

struct Node {
  // unsigned short int data;
  char data;
  unsigned short int char_count;

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
  printf("%c:%d - ", tree_root->data, tree_root->char_count);
  if (tree_root->lesserChild != NULL) {
    print_preorder (tree_root->lesserChild);
  }
  if (tree_root->greaterChild != NULL) {
    print_preorder (tree_root->greaterChild);
  }
}

void* print_postorder (struct Node *tree_root)
{
  if (tree_root->lesserChild != NULL) {
    print_postorder (tree_root->lesserChild);
  }
  if (tree_root->greaterChild != NULL) {
    print_postorder (tree_root->greaterChild);
  }
  printf("char-%c:count - %d\n", tree_root->data, tree_root->char_count);
  char *node_value = (char*)malloc(sizeof(char)*3);
  *(node_value) = (signed char)tree_root->data;
  *(node_value+sizeof(char)) = (unsigned char)tree_root->char_count;
  // *(node_value+sizeof(char)*2) = (unsigned char)(tree_root->char_count+sizeof(char));

  char *krishwantstoprintEVERYTHING = node_value;

//http://stackoverflow.com/questions/6373093/how-to-print-binary-number-via-printf?answertab=active#tab-top
  for (int i = 0; i < 24 ;++i) {
    if (*krishwantstoprintEVERYTHING & 1)
        printf("1");
    else
        printf("0");
    *krishwantstoprintEVERYTHING >>= 1;

  }
  printf("\n");

  printf("node_value[1] : %d\n", node_value[1]);

  printf(  "countOfarr : %d\n", (short unsigned int)*( node_value+sizeof(char) )  );
  // printf("sizeof countOfarr : %lu\n", sizeof((short unsigned int)*( node_value+sizeof(char) ) ) );
  return node_value;
}

int main(void)
{
  char string[] = "cobross";
  struct Node word_root;
  word_root.data = string[0];
  word_root.char_count = 544;
  word_root.parent = NULL;
  word_root.lesserChild = NULL;
  word_root.greaterChild = NULL;
  // word_root.leftMostChild = NULL;
  // word_root.rightSibling = NULL;

  struct Node* temp_node = &word_root;
  temp_node->data = word_root.data;
  for (int i = 1; string[i] != '\0'; ++i) {
    struct Node* new_node = create_node(string[i]);
    add_node(&word_root, new_node);
  }

  printf("preorder\n");
  print_preorder(&word_root);
  printf("\n");


  printf("postorder\n");
  void *postorder_value = print_postorder(&word_root);

  printf("\n");
  printf("@: %p\n", (void*) &postorder_value);
  printf("@+1: %p\n", (void*)&postorder_value+1);

  printf("postorder value: %c\n", (char) postorder_value);
  printf("postorder value+1: %d\n", (unsigned short int)++postorder_value);

  printf("postorder_value: %d\n", (unsigned short int)postorder_value+1);
  printf("v+1: %d\n", (unsigned short int)++postorder_value);
  printf("postorder_value: %d\n", (unsigned short int)postorder_value+1);

  // printf("array index of [%d]\n", hash);

  return 0;
}