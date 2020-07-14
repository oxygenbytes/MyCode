#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        // 处理特殊输入
        if(pHead1 == nullptr) return pHead2;
        if(pHead2 == nullptr) return pHead1;

        ListNode *new_head = nullptr;
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        ListNode *p;
        ListNode *temp;
        // 分析循环终止条件
        while(p1  && p2){
            if(p1->val < p2->val){
                p -> next = p1;
                p1 = p1 -> next;
            }
            else{
                p -> next = p2;
                p2 = p2 -> next;
            }
            if(new_head == nullptr)
                new_head = p -> next;
            p = p -> next;
        }
        // 通过程序(数据结构状态)来确定代码细节,关注数据结构的临界状态，以确定程序分支
        // 指明数据结构状态变换的方向，剩下的交给计算机来做。
        if(p2 != nullptr) p -> next = p2;
        else p -> next = p1;

        return new_head;
    }
};

int main(){
    ListNode *head = new ListNode(0);
    ListNode *head2 = new ListNode(1);
    ListNode *temp;
    ListNode *curr = head;
    for(int i = 3; i < 27;i+=3){
        temp = new ListNode(i);
        curr -> next = temp;
        curr = curr -> next;
    }
    ListNode *curr2 = head2;
    for(int i = 4; i < 27;i+=3){
        temp = new ListNode(i);
        curr2 -> next = temp;
        curr2 = curr2 -> next;
    }
    Solution s;
    ListNode *new_head =  s.Merge(head, head2);
    while(new_head -> next != nullptr){
        cout<<new_head->val<<" ";
        new_head = new_head -> next;
    }
    return 0;

}