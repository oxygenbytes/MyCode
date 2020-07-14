#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode * right;
    TreeNode(int x):
    val(x),left(NULL),right(NULL){}
};
class Solution{
public:
    bool IsBalanced_Solution(TreeNode *pRoot){
        bool res = true;
        if(pRoot == NULL)   return res;
        int d;
        res = isBalanced(pRoot,d);
        return res;       
    }
    bool isBalanced(TreeNode *pRoot,int &d){
        int dl,dr;
        bool res = true;
        dl = dr = 0;
        if(pRoot){
            res = isBalanced(pRoot->left,dl) && isBalanced(pRoot->right,dr);// 左子树，右子树分别是二叉搜索树
            res = res && ( abs(dl - dr) <= 1); // 高度是核心判据
            d = max(dl,dr) + 1;
        }
        return res;
    }
};