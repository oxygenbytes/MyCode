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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr)
            return ans;
        deque<TreeNode*> queue;
        queue.push_back(root);
        // 这里要注意的是：因为是层次遍历，而队列中的元素刚好是按照层次遍历的顺序进队列的
        // 所以每次循环只打印一个节点，同时处理这个节点的子节点
        while(!queue.empty()){
            TreeNode * temp = queue.front();
            ans.push_back(temp->val);
            if(temp->left)
                queue.push_back(temp->left);
            if(temp->right)
                queue.push_back(temp->right);
            queue.pop_front();
        }
        return ans;
        
    }
};

int main(){
    TreeNode *head = new TreeNode(0);
    TreeNode *ltemp ;
    TreeNode *rtemp ;
    for (int i = 5; i <= 40; i+=10)
    {
        TreeNode *le = new TreeNode(i);
        TreeNode *re = new TreeNode(i + 5);

        if(head -> left == nullptr){
            head -> left = le;
            ltemp = le;
        }
            
        else
        {
            ltemp -> left = le;
            ltemp = ltemp -> left;
        }
        
        if(head->right == nullptr){
            head -> right = re;
            rtemp = re;
        }
        else
        {
            rtemp -> right = re;
            rtemp = rtemp -> right;
        }
        

    }
    Solution s;
    vector<int> v;
    v = s.PrintFromTopToBottom(head);
    for(int i : v)
        cout<<i<<endl;
    return 0;
    
}