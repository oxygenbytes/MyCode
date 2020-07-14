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
        vector<vector<int> > result;
        if(pRoot == nullptr)
            return result;
        stack<TreeNode*> s1;      
        stack<TreeNode*> s2;
        s1.push(pRoot);
        TreeNode *temp;
        vector<int> Level;

        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                while(!s1.empty()){
                    temp = s1.top();
                    Level.push_back(temp->val);
                    if(temp->left)
                        s2.push(temp->left);
                    if(temp->right)
                        s2.push(temp->right);
                    s1.pop();
                }
                result.push_back(Level);
                Level.clear();
            }
            else{
                while(!s2.empty()){
                    temp = s2.top();
                    Level.push_back(temp->val);
                    if(temp->left)
                        s1.push(temp->left);
                    if(temp->right)
                        s1.push(temp->right);
                    s2.pop();
                }
                result.push_back(Level);
                Level.clear();
            }
        }    
        return result;
    }
};