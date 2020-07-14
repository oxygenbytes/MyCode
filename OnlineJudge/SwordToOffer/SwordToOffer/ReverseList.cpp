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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == nullptr || pHead -> next == nullptr)
            return pHead;
        ListNode *prev = pHead;
        ListNode *curr = pHead -> next;
        ListNode *temp = pHead -> next -> next;
        while(curr != nullptr){
            curr -> next = prev;
            prev = curr;
            curr = temp ;
            temp = temp -> next;
        }
        pHead -> next = NULL;
        return prev;

    }
public:
    ListNode* reverseList(ListNode* head){ 
        //剑指offer中的解法，是唯一一种能够通过的倒转链表解法，呜呜呜，做了半天
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *new_head = nullptr;

        while(curr != nullptr){
            ListNode *temp = curr -> next;
            if(temp == nullptr)
                new_head = curr;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return new_head;
    }
};

class Solution_recursion{
public:
    ListNode* Reverse(ListNode *head){
        //使用递归解决链表反转的思路
        // 0 -> 0 -> 0 -> 0 -> 0
        // 0 <- [0 -> 0 -> 0 -> 0] [ ]中为新的函数对象
        // 分析这个函数的返回值可以知道，Reverse函数的每一次调用，返回的都是最终的头结点
        // 被调用方的Reverse函数将会返回最后的头结点，这个返回值又会作为调用方的返回值
        if(head == nullptr || head -> next == nullptr)
            return head;
        ListNode *new_head = Reverse(head->next);
        cout<<new_head->val<<" ";
        head -> next -> next = head;
        head -> next = nullptr;
        return new_head;
        
    }
};
int main(){
    ListNode *head = new ListNode(0);
    ListNode *temp;
    ListNode *curr = head;
    for(int i = 3; i < 27;i+=3){
        temp = new ListNode(i);
        curr -> next = temp;
        curr = curr -> next;
    }
    Solution_recursion s;
    ListNode *new_head =  s.Reverse(head);
    while(new_head -> next != nullptr){
        cout<<new_head->val<<" ";
        new_head = new_head -> next;
    }
    return 0;

}