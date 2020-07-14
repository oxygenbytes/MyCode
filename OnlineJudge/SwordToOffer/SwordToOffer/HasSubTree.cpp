#include <bits/stdc++.h>
using namespace std;

strcut TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :  // 注意这里的：冒号
        val(x),left(NULL),right(NULL){} //注意，构造函数要有参数
};
// 递归什么时候高效？
// 当一个函数调用自身两次时候，这个时候递归比较高效，因为类似于2^n这种模式，栈不会太长。
// 同时，这种时候使用递归时，函数本身的参数是有要求的，比如对于给定数据结构边界的约束限制
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        // 递归的基本思想是某个函数直接或者间接地调用自身，
        // 这样就把原问题的求解转换为许多性质相同但是规模更小的子问题。
        // 我们只需要关注如何把原问题划分成符合条件的子问题，而不需要去研究这个子问题是如何被解决的。
        bool result = false;
        if(pRoot1 != nullptr && pRoot2 != nullptr){
            if(pRoot1->val == pRoot2->val)
                result = DoesTreeHasSubTree(pRoot1,pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->left,pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->right,pRoot2);
        }
        return result;
    }
    // 递归的技巧
    // 我的一点心得是： 明白一个函数的作用并相信它能完成这个任务，千万不要试图跳进细节。 
    // 千万不要跳进这个函数里面企图探究更多细节，否则就会陷入无穷的细节无法自拔，人脑能压几个栈啊。
    bool DoesTreeHasSubTree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if(pRoot2 == nullptr)
             return true;
        if(pRoot1 == nullptr)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        return DoesTreeHasSubTree(pRoot1->left, pRoot2->left) &&
            DoesTreeHasSubTree(pRoot1->right,pRoot2->right);
    }
};
