#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):
    val(x),next(nullptr){}
};
class Solution{
public:
    ListNode* EntryNodeOfLoop(ListNode *pHead){
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next -> next;
            slow = slow->next;
            if(fast == slow){ // 说明有环，内部程序是为了寻找环的入口节点
                ListNode *p = pHead;
                while(p!=slow){ 
                    p = p -> next; // 使用双指针来让实现一趟遍历并做标记
                    slow = slow -> next;
                }
                return p;
            }
        }
        return nullptr;
    }
};