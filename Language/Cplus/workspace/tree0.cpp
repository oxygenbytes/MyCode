#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node* left;
    node* right;
}Node;

void preorder(Node* node){
    if(node != NULL){
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }
    return ;
    
}

int main(){
    struct node n1;
    struct node n2;
    struct node n3;
    struct node n4;

    n1.data = 6;
    n2.data = 4;
    n3.data = 10;
    n4.data = 9;

    n1.left = &n2;
    n1.right = &n4;
    n2.left = NULL;
    n2.right = &n3;
    n3.left = NULL;
    n3.right = NULL;
    n4.left = NULL;
    n4.right = NULL;

    preorder(&n1);
}