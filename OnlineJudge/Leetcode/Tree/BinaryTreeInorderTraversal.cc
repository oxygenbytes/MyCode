// Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return result;
    }
private:
    vector<int> result;
    void dfs(TreeNode* root){
        if(root){
            dfs(root->left);
            result.push_back(root->val);
            dfs(root->right);
        }
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)  return result;
        stack<TreeNode*> s;
        TreeNode* ptr = root;
        
        while(!s.empty() || ptr){ // 栈不空or指针不空  
            if(ptr){ // 1. 指针不空and栈不空  2. 指针不空and栈空
                s.push(ptr);
                ptr = ptr->left;
            }else{ // 2. 指针空and栈不空 4. 指针空and栈空（没有这个玩意，不符合while循环）
                ptr = s.top();s.pop(); // 栈内节点状态：左节点已经处理，自己和右节点还没处理
                result.push_back(ptr->val);
                ptr = ptr->right;
            }
        }
        return result;
    }
};