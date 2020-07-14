#include <bits/stdc++.h>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x):
        label(x), next(NULL),random(NULL){
        }
};

class Solution{
public:
    RandomListNode* Clone(RandomListNode* pHead){
        if(pHead == nullptr) 
            return pHead;
        RandomListNode *p = pHead; // 不是由某个节点所拥有的指向节点指针，我称之为上帝指针
        RandomListNode *pnext = NULL;

        while(p != nullptr)
        {
            pnext = p -> next; 
            // next指针同样是指向节点的指针，但是因为其被某个节点所拥有，所以称之为木偶指针
            // 可以想象，上帝指针是木偶线，节点指针则是木偶的手（可以抓另一个木偶）
            // 很明显，二者是不相同的，可以将指针之间的赋值比作，木偶之间重新组合的过程
            p -> next = new RandomListNode(p->label);
            p -> next -> next = pnext;
            p = pnext;
        }
        // 在使用指针的时候，一定要注意，空指针不能解引用
        RandomListNode *cp = NULL;
        p = pHead;

        while(p != nullptr){
            cp = p -> next;
            pnext = p -> next -> next;
            cp -> random = (p -> random != nullptr) ? p -> random -> next: nullptr; 
            // a -> a() -> b -> b() -> nullptr
            // 注意这里的a -(random)-> b
            // 而 a() -(random)-> b()
            p = pnext;
        }

        RandomListNode *res = pHead -> next;
        p = pHead;

        while(p != nullptr){
            cp = p -> next;
            pnext = cp -> next;
            p -> next = pnext;
            cp -> next = (pnext != nullptr) ? pnext->next:NULL;
            p = pnext;
        }
        return res;
    }
};