#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 牢记递归的两个关键点：
// 1. 终止条件  定义最简单子问题的解决方案
// 2. 自我调用  使用解决父问题的办法去解决子问题
// 写递归的技巧
// 明白一个函数的作用并相信他能完成这个任务，千万不要试图从细节上分析递归代码，否则很容易陷入无穷的细节中搞得疲惫不堪，人脑能压几个栈啊？
// 还是那句话，明白每个递归函数能做的事，并相信他们能够完成。
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    if(pre.size()==0 || vin.size()==0)
        return nullptr;
    TreeNode *head = new TreeNode(pre[0]);
    
    vector<int> left_pre, left_vin;
    vector<int> right_pre, right_vin;
    
    int index = 0;
    int len = pre.size();
    
    for(int i = 0;i < len ;i++){
        if(vin[i] == pre[0]){
            index = i;
            break;
        }
            
    }
    cout<<index<<endl;
    for(int i=0 ; i<index;i++){
        left_pre.push_back(pre[i+1]);
        left_vin.push_back(vin[i]);
        
    }
    
    for(int i = index + 1; i < len; i++){
        right_vin.push_back(vin[i]);
        right_pre.push_back(pre[i]);
    }
    head -> left = reConstructBinaryTree(left_pre,left_vin);
    head -> right = reConstructBinaryTree(right_pre,right_vin);
    
    return head;
    
}

void preOrder(TreeNode *head){
    if(head == nullptr){
        return ;
    }
    cout<<head -> val<<endl;
    preOrder(head -> left);
    preOrder(head -> right);
}

void preOrder2(TreeNode *head){
    // 遇空指针则弹出栈顶元素
    //结束条件是遍历指针为空，而且栈中无元素
    stack<TreeNode *> s;
    TreeNode *p = head;
    while(p != nullptr || !s.empty()){
        while(p != nullptr){
            cout<< p -> val <<endl;
            s.push(p);
            p = p -> left;
        }
        if(!s.empty()){
            p = s.top();
            p = p -> right;
            s.pop();
        }
    }
}

int main(){
    vector<int> arr1 = {1,2,4,7,3,5,6,8};
    vector<int> arr2 = {4,7,2,1,5,3,8,6};
    TreeNode *head = NULL;
    head = reConstructBinaryTree(arr1,arr2);
    cout<<head->val<<endl;
    cout<<head->left->val<<endl;
    cout<<head->right->val<<endl;
    cout<<"********************"<<endl;
    preOrder(head);
    cout<<"********************"<<endl;
    preOrder2(head);
    return 0;
}