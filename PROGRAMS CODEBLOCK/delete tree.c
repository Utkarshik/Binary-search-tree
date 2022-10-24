#include<stdio.h>
#include<stdlib.h>
struct node {
   int data;
   struct node* left;
   struct node* right;
};
struct node* addnode(int data) {
   struct node* node = (struct node*)
      malloc(sizeof(struct node));
   node->data = data;
   node->left = NULL;
   node->right = NULL;
   return(node);
}
void nodedel(struct node* node) {
   if (node == NULL) return;
   nodedel(node->left);
   nodedel(node->right);
   printf("Node deleted, value is %d", node->data);
   free(node);
}
int main() {
   struct node *root = addnode(9);
   root->left = addnode(4);
   root->right = addnode(15);
   root->left->left = addnode(2);
   root->left->right = addnode(6);
   root->right->left = addnode(12);
   root->right->right = addnode(17);
   nodedel(root);
   root = NULL;
   printf(" Tree deleted ");
   return 0;
}
