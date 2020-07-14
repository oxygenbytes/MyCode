#include <bits/stdc++.h>
using namespace std;

class Deque
{
public:
    void push(int node) {
        stack1.push(node);
    }


    int pop() {
        int t;
        if(stack2.empty()){
            while(!stack1.empty()){
                    t = stack1.top();
                    stack2.push(t);
                    stack1.pop();
            }
        }
         int pop_element = stack2.top();
         stack2.pop();
        return pop_element;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
    Deque d ;
    for(int i = 0;i<4;i++){
        d.push(i);
    }
    cout<<d.pop()<<endl;
    d.push(3);
    cout<<d.pop()<<endl;
    cout<<d.pop()<<endl;
    return 0;
}