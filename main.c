#include <malloc.h>
#include <stdio.h>

typedef struct Node {
  struct Node *RightNode;
  struct Node *LeftNode;
  int value;
} Tree;

Tree *createNode(int val);
Tree *insertNode(Tree *node, int val);
void showTree(Tree *node, int tabCount);
void preOrder(Tree *node);
void inOrder(Tree *node);
void postOrder(Tree *node);
void tabFormat(int val);
Tree *removeNode(Tree *node, int val);
Tree *findMinimum(Tree *node);

int main(void) {
  Tree *Node = createNode(25);
  // example input
  insertNode(Node, 22);
  insertNode(Node, 23);
  insertNode(Node, 24);
  insertNode(Node, 21);
  insertNode(Node, 20);
  insertNode(Node, 29);
  insertNode(Node, 28);
  insertNode(Node, 30);
  insertNode(Node, 27);
  insertNode(Node, 35);
  insertNode(Node, 33);
  insertNode(Node, 38);
  insertNode(Node, 55);
  insertNode(Node, 37);
  showTree(Node, 0);
  puts("\nPre Order:\n");
  preOrder(Node);
  puts("\n\nIn Order:\n");
  inOrder(Node);
  puts("\n\nPost Order:\n");
  postOrder(Node);
  puts("\n\n");
  removeNode(Node, 25);
  showTree(Node, 0);
  
  return 0;
}

// creates a new node
Tree *createNode(int val) {
  Tree *newNode = (Tree *)malloc(sizeof(Tree));
  newNode->RightNode = NULL;
  newNode->LeftNode = NULL;
  newNode->value = val;
  return newNode;
}

Tree *search(Tree *root,int value){
  if(root == NULL){
    return NULL;
  }
  if(root->value == value){
    return root;
  }
  if(value < root->value){
    return search(root->LeftNode, value);
  }else{
    return search(root->RightNode, value);
  }

}

Tree *removeNode(Tree *root,int value){
  if(root == NULL){
    return NULL;
  }
  if(value < root->value){
    root->LeftNode = removeNode(root->LeftNode, value);
  } else if(value > root->value){
    root->RightNode = removeNode(root->RightNode, value);
  } else{
    if(root->LeftNode == NULL && root->RightNode == NULL){
      root = NULL;
      return NULL;
    }
    if(root->LeftNode == NULL){
      Tree *temp = root->RightNode;
      root = NULL;
      return temp;
    }
    else if(root->RightNode == NULL){
      Tree *temp = root->LeftNode;
      root = NULL;
      return temp;
    }

    Tree *minimumNode = findMinimum(root->RightNode);
    root->value = minimumNode->value;
    root->RightNode = removeNode(root->RightNode, minimumNode->value);
  }
  
  return root;
}


Tree *findMinimum(Tree *node){
  while(node->LeftNode){
    node = node->LeftNode;
  }
  return node;
}


void tabFormat(int val) {
  for (int i = 0; i < val * 2; i++) {
    printf("-");
  }
}

Tree *insertNode(Tree *node, int val) {
  if (node == NULL) {
    node = createNode(val);
    return node;
  }
  if (val < node->value) {
    node->LeftNode = insertNode(node->LeftNode, val);
  } else if (val > node->value) {
    node->RightNode = insertNode(node->RightNode, val);
  }
  return node;
}

void showTree(Tree *node, int tabCount) {
  if (node) {
    tabFormat(tabCount);
    printf("|%d \n", node->value);
    showTree(node->RightNode, tabCount + 1);
    showTree(node->LeftNode, tabCount + 1);
  }
}

void preOrder(Tree *node) {
  if (node) {
    printf("|%d ", node->value);
    preOrder(node->LeftNode);
    preOrder(node->RightNode);
  }
}

void inOrder(Tree *node) {
  if (node) {
    inOrder(node->LeftNode);
    printf("|%d ", node->value);
    inOrder(node->RightNode);
  }
}

void postOrder(Tree *node) {
  if (node) {
    postOrder(node->LeftNode);
    postOrder(node->RightNode);
    printf("|%d ", node->value);
  }
}
