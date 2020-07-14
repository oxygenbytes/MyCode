//思路：不管三七二十一，先走到树的最左边
// 然后将该节点作为根节点，检查其右子树是否为空或者已经处理掉，处理掉的右子树会带着标记的q指针
//通过检查的节点中的值可以被回收，弹出对应的栈顶指针
//使用了new，一定要使用delete，否则会发生内存泄露
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode *> s;
    TreeNode *p = root, *q = nullptr;
    do{
        while(p != nullptr){
            s.push(p);
            p = p -> left;
            
        }
        // cout<<"kk";
        q = nullptr;
        while(!s.empty()){
            p = s.top();
            // cout<<p->val;
            cout<<p->val<<endl;
            s.pop();
            if(p->right == q){ //p是标志，用于标记该节点的右子树已经被处理过，所以可以处理该节点了
                result.push_back(p->val);
                q = p;
                cout<<q->val<<endl;
            }else{
                s.push(p);
                p = p->right;
                break;
            }
            // cout<<endl;
        }
    }while(!s.empty());
    return result;
}
int main(){
    TreeNode *t1 = new TreeNode(3);
    TreeNode *t2 = new TreeNode(24);
    TreeNode *t3 = new TreeNode(6);
    TreeNode *t4 = new TreeNode(2);
    TreeNode *t5 = new TreeNode(12);
    TreeNode *t6 = new TreeNode(4);
    t1->left = t2;
    t2->left = t3;
    t3->right = t4;
    t1->right = t5;
    t5->right = t6;

    vector<int> list = postorderTraversal(t1);
    for(int i : list){
        cout<<i<<" ";
    }
    delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete t5;
    delete t6;
    return 0;

}