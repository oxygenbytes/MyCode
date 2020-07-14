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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> res;
            if(pRoot == nullptr)
                return res;
            vector<int> lineRes;
            queue<TreeNode*> q;
            TreeNode* temp;
            q.push(pRoot);
            while(!q.empty()){
                int low = 0,high = q.size();
                while(low++ < high){
                    temp = q.front();
                    lineRes.push_back(temp->val);
                    q.pop();
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
                res.push_back(lineRes);
                lineRes.clear();
            }
            return res;
        }
};