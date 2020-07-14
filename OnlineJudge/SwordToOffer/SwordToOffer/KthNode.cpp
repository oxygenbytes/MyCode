#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == nullptr || k <= 0)  return nullptr;
        vector<TreeNode*> v;
        Inorder(pRoot,v);
        if(k > v.size())      
            return nullptr;
        return v[k-1];
    }
    void Inorder(TreeNode* pRoot,vector<TreeNode*>& v){
        if(pRoot == nullptr)    return;
        Inorder(pRoot->left,v);
        v.push_back(pRoot);
        Inorder(pRoot->right,v);
    }
};