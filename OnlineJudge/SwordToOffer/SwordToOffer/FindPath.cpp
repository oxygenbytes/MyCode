#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
};
// 还是没有形成使用递归解决跟树相关的问题这种习惯，
// 递归解决树问题，回溯用栈，层次遍历用队列
class Solution{
public:
    vector<vector<int>> result;
    vector<int> temp;

    vector<vector<int>> FindPath(TreeNode *root,int exceptNumber){
        if(root != nullptr)
            findOnePath(root,exceptNumber);
        return result;
    }
// 根节点压入vector, 然后分别在左右子树上寻找exceptNumber值等于exceptNumber-root->val的通路
// 还有一点就是使用栈结构，下潜时，下到哪压到哪，回溯时，上到哪弹到哪
    void findOnePath(TreeNode *root,int exceptNumber){
        temp.push_back(root->val);
        if(exceptNumber - root->val == 0 && root->right == nullptr && root->left == nullptr)
            result.push_back(temp);
        if(root->left != nullptr) 
            findOnePath(root->left,exceptNumber-root->val);
        if(root->right != nullptr)
            findOnePath(root->right,exceptNumber-root->val);
        temp.pop_back();
    }
};

