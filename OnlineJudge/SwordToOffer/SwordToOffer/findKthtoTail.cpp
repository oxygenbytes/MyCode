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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr)
            return nullptr;
        ListNode *prev = pListHead;
        ListNode *curr = pListHead;
        for(int i = 0 ; i < k - 1;i++){
            prev = prev -> next;
            if(prev -> next == nullptr)
                return nullptr;
            
        }
        while(prev -> next != nullptr){
            prev = prev -> next;
            curr = curr -> next;
        }
        return curr;
    }
public:
    ListNode* FindKthToTail_answer(ListNode* pListHead, unsigned int k) {
        if(pListHead == nullptr || k == 0)
            return nullptr;
        ListNode *prev = pListHead;
        ListNode *curr = nullptr;
        for(unsigned int i = 0 ; i < k - 1;i++){ //注意[0,k-1) 循环进行k-1次
            if(prev->next != nullptr) //而倒着计数的时候，是从1开始的，[1,k) 循环进行k-1次
                prev = prev -> next;
            else
                return nullptr;   
        }
        curr = pListHead;
        while(prev -> next != nullptr){
            prev = prev -> next;
            curr = curr -> next;
            cout<<curr->val<<" "<<prev->val<<endl;
        }
        return curr;
    }

};


int main(){
    ListNode *head = new ListNode(-3);
    ListNode *temp ;
    ListNode *curr = head;
    for(int i=0;i<38;i+=3){
        temp = new ListNode(i);
        curr -> next = temp; //此处曾经写反，将nullptr赋值给其他指针
        curr = curr -> next;
    }
    Solution s;
    cout<<s.FindKthToTail(head,4) -> val<<endl;
    return 0;
}