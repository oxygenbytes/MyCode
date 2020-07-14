#include <bits/stdc++.h>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution{
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode){
        if(!pNode) return pNode;
        if(pNode->right == nullptr){ // 不存在右节点，找第一个父子关系为左的祖先节点中的父节点
            while(pNode && pNode->next && pNode == pNode->next->right)
                pNode = pNode->next;
            return pNode->next;
        }
        // 存在右节点，找右子树最左节点
        pNode = pNode->right;
        while(pNode && pNode->left) pNode = pNode->left;
        return pNode;
    }
};