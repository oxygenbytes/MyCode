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
    ListNode * deleteDuplication(ListNode* pHead){
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode p1 = new ListNode(0);
        p1->next = pHead;
        ListNode *head = p1;
        ListNode* p2 = pHead;
        while(p2){
            if(p2->next && p2->val == p2->next->val){
                while(p2->next && p2->val == p2->next->val){
                    p2 = p2 -> next;
                }
                p2 = p2 -> next;
                p1->next = p2;
            }
            else{
                p1 = p2;
                p2 = p2 -> next;
            }
        }
        return head->next;
    }
};