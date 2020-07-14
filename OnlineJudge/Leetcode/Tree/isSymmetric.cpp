// leetcode 101. 对称二叉树
#include <bits/stdc++.h>
using namespace std;


//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// 递归解决这个问题
// 注意递归要定义问题边界，也就是下面的Symmetric()函数，只有这样才能不断缩小问题的规模
// 递归的三要素：1结束条件 2调用自身解决子问题 3问题范围边界

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
                return true;
        return Symmetric(root->left,root->right);        
    }
    bool Symmetric(TreeNode* left_node,TreeNode* right_node){
        if(left_node == nullptr && right_node == nullptr) return true;
        if(left_node == nullptr && right_node != nullptr ) return false;
        if(right_node == nullptr && left_node != nullptr ) return false;
        if(left_node->val != right_node->val) return false;
        return Symmetric(left_node->left,right_node->right) && Symmetric(left_node->right,right_node->left);
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode* root){
        if(root == nullptr)
            return false;
        queue<int> q1;
        queue<int> q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
            TreeNode* node1 = q1.front();q1.pop();
            TreeNode* node2 = q2.front();q2.pop();
            if(!node1&&!node2) continue;
            if((!node1&&node2) ||(node1&&node2)||(node1->val!=node->val)) return false;
            q1.push(node->left);
            q1.push(node->right);
            q2.push(node->right);
            q2.push(node->left);
        }
        return true;
    }
};