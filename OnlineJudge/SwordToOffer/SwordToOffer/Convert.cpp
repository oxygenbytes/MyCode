#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){

    }
};
/* 关于递归
1. 结束条件 2. 调用自身 3. 问题范围边界
如何写出递归程序
首先绘出基本的递归调用关系（递归树/递归链) 
当身处递归的某一层时，此时该层具有双重身份
 a. 是下一层的父亲调用  此时该调用比儿子调用晚结束，并且要利用儿子调用返回的结果
 b. 是上一层的儿子调用  此时该调用比上层调用早结束，并且其返回的结果将被上层调用使用
 */
/* 递归调用树，父函数-->调用自身---->子函数------>控制权回归父函数
             Convert(1)
              /     \
             /       \
        Convert(2)  Convert(3)
        /     \         /   \
       /       \       /     \
Convert(4)Convert(5)Convert(6)Convert(7)
这个里面最先结束的函数是Convert(4),最后结束的是Convert(1)
       */  
class Solution{
public:
    TreeNode* Convert(TreeNode *pRootOfTree){
        if(pRootOfTree == nullptr)
            return nullptr;
        if(pRootOfTree->left == nullptr && pRootOfTree->right == nullptr)
        {
            leftLast = pRootOfTree;
            return pRootOfTree;
            
        }
        
        TreeNode *pleft = Convert(pRootOfTree->left);
        if(pleft != nullptr){
            leftLast->right = pRootOfTree;
            pRootOfTree->left = leftLast; 
            // 这里的leftLast保存的是子树的最大值，因为上面的Conver函数执行完了
        }
        leftLast = pRootOfTree; // 画出递归树可以知道，倘若左子树处理完后，如果没有右子树
        // 此时倘若没有这条语句，则leftLast记录的就不是左子树的最大点
        // 递归树有助于分析递归的运行过程，不要用人脑压栈，会爆掉的
        TreeNode *pright = Convert(pRootOfTree->right);
        if(pright != nullptr)
        {
            pright -> left = pRootOfTree;
            pRootOfTree->right = pright;
        }    

        return pleft != nullptr ? pleft:pRootOfTree;
    }
protected:  
    TreeNode *leftLast = nullptr;
};