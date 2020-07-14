#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void push(int value) {
        stack1.push(value);
    }
    void pop() {
        stack1.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        int min = 0;
        if(!stack1.empty()){
            min = stack1.top();
            stack2.push(min);
            stack1.pop();
        }
        while(!stack1.empty()){
            if(min > stack1.top()){
                min = stack1.top();
                stack2.push(min);
                stack1.pop();
            }else{
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return min;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
    Solution s;
    s.push(3);
    s.push(4);
    cout<<s.min()<<endl;
    s.push(5);
    cout<<s.min()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    return 0;
}