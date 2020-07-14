#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
};

void Mirror(TreeNode *pRoot){
    if(pRoot == nullptr || (pRoot->left == nullptr) && (pRoot->right == nullptr))
        return ;

    TreeNode *temp = pRoot -> left;
    pRoot -> left = pRoot -> right;
    pRoot -> right = temp;

    if(pRoot->left != nullptr)
         Mirror(pRoot->left);
    if(pRoot->right != nullptr)
         Mirror(pRoot->right);
    
}

void LevelOrder(TreeNode *head){
    queue<TreeNode *> qu;
    if(head) 
        qu.push(head);
    while(!qu.empty())
    {
        TreeNode *temp = qu.front();
        cout<<temp->val<<" ";

        qu.pop();

        if(temp->left) 
            qu.push(temp->left);
        if(temp->right)
            qu.push(temp->right);
        
    }
    return ;
}
int main(){
    TreeNode *head = new TreeNode(0);
    TreeNode *ltemp ;
    TreeNode *rtemp ;
    for (int i = 5; i <= 40; i+=10)
    {
        TreeNode *le = new TreeNode(i);
        TreeNode *re = new TreeNode(i + 5);

        if(head -> left == nullptr){
            head -> left = le;
            ltemp = le;
        }
            
        else
        {
            ltemp -> left = le;
            ltemp = ltemp -> left;
        }
        
        if(head->right == nullptr){
            head -> right = re;
            rtemp = re;
        }
        else
        {
            rtemp -> right = re;
            rtemp = rtemp -> right;
        }
        

    }
    LevelOrder(head);
    Mirror(head);
    cout<<endl;
    LevelOrder(head);
    return 0;
    
}