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
    char* Serialize(TreeNode *root) {    
        if(root == nullptr)
            return nullptr;
        string str;
        Serialize(root,str);
        char *ret = new char[str.length()+1];
        int i;
        for(i = 0;i < str.length();i++){ // int i :wrong
            ret[i] = str[i];
        }
        ret[i] = '\0';
        return ret;
    }
    void Serialize(TreeNode *root,string &str){
        if(root == nullptr){
            str += '#';
            return;
        }
        string  r = to_string(root->val);
        str += r;
        str += ',';
        Serialize(root->left,str);
        Serialize(root->right,str);
    }
    TreeNode* Deserialize(char *str) {
        if(str == nullptr)
            return nullptr;
        TreeNode *ret = Deserialize(&str);
        return ret;
    }
    TreeNode* Deserialize(char **str){
        if(**str == '#'){
            ++(*str);
            return nullptr;
        }
        int num = 0;
        while(**str != '\0' && **str != ','){
            num = num*10 + ((**str) - '0');
            ++(*str);
        }
        TreeNode *root = new TreeNode(num);
        if(**str == '\0')
            return root;
        else
            (*str)++;
        
        root->left = Deserialize(str);
        root->right = Deserialize(str);
        return root;
    }
};