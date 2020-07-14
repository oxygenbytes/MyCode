// KthNode

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
};

class Solution {
    vector<TreeNode*> vec;
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr || k <= 0) return nullptr;
        inOrder(pRoot);
        if(k > vec.size())
            return nullptr;
        return vec[k-1];
    }

    void inOrder(TreeNode* pRoot){
        if(pRoot){
            inOrder(pRoot->left);
            vec.push_back(pRoot);
            inOrder(pRoot->right);
        }
    }
};