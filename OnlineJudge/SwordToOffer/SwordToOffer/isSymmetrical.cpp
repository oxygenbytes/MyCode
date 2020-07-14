#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):
    val(x),left(NULL),right(NULL) {

    }
};
class Solution{
public:
    bool isSymmetrical(TreeNode* pRoot){
        if(pRoot == NULL) return true;
        bool res = isSymmertic(pRoot->left,pRoot->right);
        return res;
    }
    bool isSymmertic(TreeNode* left,TreeNode *right){
        if(left == nullptr && right == nullptr) 
            return true;
        if(left == nullptr || right == nullptr)
            return false;
        if(left->val != right->val)
            return false;
        return isSymmertic(left->left,right->right) && isSymmertic(left->right,right->left);
    }
};