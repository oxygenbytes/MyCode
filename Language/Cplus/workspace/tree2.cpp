// struct  Student   
// {   
//     int   a;   
// }stu1;//stu1是一个变量 
  
// typedef   struct   Student2   
// {   
//     int   a;   
// }stu2;//stu2是一个结构体类型   
#include <iostream>
#include <stack>
using namespace std;

typedef struct anode{
    int value;
    struct anode* left;
    struct anode* right;
}Node;

typedef struct 
{
    Node* root;
}Tree;

void insert(Tree* tree, int value){
    // 先将value打包成节点
    Node* node = new Node;
    node->value = value;
    node->left =  NULL;
    node->right = NULL;

    if(tree->root == NULL){
        tree -> root = node;
    }
    else{
        Node* temp = tree->root;
        while(temp != NULL){
            if(temp->value > value){
                if(temp->left ==NULL){
                    temp->left = node;
                    return ;
                }
                    
                else
                {
                    temp = temp -> left;
                }
                
            }
            else{
                if(temp->right == NULL){
                    temp->right = node;
                    return ;
                }
                else{
                    temp = temp -> right;
                }

            }
        }
    }

}
void preorder(Node* node){
    if(node != NULL){
        cout<<node->value<<" ";
        preorder(node->left);
        preorder(node->right);
    }
    return ;
    
}
void preorder2(Node* node){
    stack<Node*> s;
    Node *p = node;
    while(p != NULL || !s.empty()){
        while(p != NULL){
            cout<<p->value<<" ";
            s.push(p);
            p = p -> left;
        }
        if(!s.empty()){
         p = s.top();
        
        p = p->right;
        s.pop();
        }
    }
}

void inorder(Node* node){
    if(node != NULL){
        
        inorder(node->left);
        cout<<node->value<<" ";
        inorder(node->right);
    }
    return ;
    
}

int main()
{
    int arr[10] = {4,2,5,12,14,1,8,10,15,6};
    Tree mytree;
    // Tree mytree2;
    // Tree mytree3;
    // cout<<&mytree<<endl;
    // cout<<&mytree2<<endl;
    // cout<<&mytree3<<endl;
    mytree.root = NULL;
    for(int i=0;i<10;i++){
        insert(&mytree, arr[i]);
    }
    // cout<<mytree.root<<endl;
    // cout<<((mytree.root)->left)<<endl;
    // inorder(mytree.root);
    // cout<<endl;
    preorder(mytree.root);
    cout<<endl;
    preorder2(mytree.root);
   
    return 0;
}

