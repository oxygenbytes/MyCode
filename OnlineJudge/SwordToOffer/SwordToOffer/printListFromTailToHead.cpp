#include <bits/stdc++.h>
using namespace std;


struct ListNode {
        int val;
        struct ListNode *next;
         ListNode(int x) :
              val(x), next(NULL) {
        }
};

vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        stack<int> s;
        int temp = 0;
        ListNode *p = head;
        while(p != nullptr){
            s.push(p->val);
            p = p -> next;
        }
        while(!s.empty()){
            temp = s.top();
            s.pop();
            v.push_back(temp);
        }
        return v;
}

int main(){
    ListNode *head = nullptr;
    ListNode *p = nullptr;
    ListNode *q = nullptr;

    for(int i = 12;i<30;i++){
        q = (ListNode *)malloc(sizeof(ListNode));
        q -> val = i;
        if(head == nullptr)
            head = q;
        else
        {
            p -> next = q;
        }
        p = q;
    }
    ListNode *test = head;
    vector<int> v;
    v = printListFromTailToHead(head);
    while(test != nullptr){
        cout<<test->val<<endl;
        test = test -> next;
    }
    cout<<"*******************"<<endl;
    for(int k : v){
        cout<<k<<endl;
    }
    return 0;
}
