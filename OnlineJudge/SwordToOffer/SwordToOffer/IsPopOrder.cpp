#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int len = pushV.size();
        if(len == 0 || len != popV.size())
            return false;
        int i = 0 , j = 0;
        stack<int> s;
        
        s.push(pushV[i++]);
        while(j < len){
            if(popV[j] == s.top()){
                s.pop();
                ++j;
                continue;
            }
            if(i < len)
                s.push(pushV[i++]);
            else
                break;
        }
        if(s.empty())
            return true;
        else 
            return false;
    }
};

int main(){
    vector<int> first = {1,2,3,4,5};
    vector<int> second = {4,5,3,1,2};
    Solution s;
    cout<<s.IsPopOrder(first,second);
    return 0;
}