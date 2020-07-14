// 两个链表在某个点合并
// 找出链表合并的起点
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x):
        val(x),next(NULL){

        }
};
class Solution{
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1,ListNode* pHead2){
        int len1 = GetListLength(pHead1);
        int len2 = GetListLength(pHead2);
        ListNode* pLong = pHead1;
        ListNode* pShort = pHead2;
        int lenDiff = len1-len2;
        if(len1 < len2){
            pLong = pHead2;
            pShort = pHead1;
            lenDiff = len1-len2;
        }
        for(int i=0;i<lenDiff;i++){
            pLong = pLong->next;
        }
        while(pLong != nullptr && pShort != nullptr && pLong != pShort){
            pLong = pLong->next;
            pShort = pShort -> next;
        }
        ListNode* pFirstCommonNode = pLong;
        return pFirstCommonNode;
    }
    unsigned int GetListLength(ListNode *pHead){
        unsigned int len = 0;
        while(pHead != NULL){
            ++len;
            pHead=pHead->next;
        }
        return len;
    }
};