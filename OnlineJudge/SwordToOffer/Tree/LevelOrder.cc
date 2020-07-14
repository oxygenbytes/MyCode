// level order binary tree

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
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(pRoot == nullptr)    
            return res;
        vector<int> line;
        TreeNode *temp;
        q.push(pRoot);
        while(!q.empty()){
            int low = 0, high = q.size();
            while(low++ < high){
                temp = q.front();
                line.push_back(temp->val);
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            res.push_back(line);
            line.clear();

        }
        return res;
    }  
};