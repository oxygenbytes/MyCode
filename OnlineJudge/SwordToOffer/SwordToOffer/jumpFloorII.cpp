#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int jumpFloorII(int number){
        if(number <= 0) return 0;
        return  pow(2,number - 1);
    }
};

class Solution2{
public:
    int jumpFloorII(int number){
        if(number <= 0) return 0;
        if(number == 1) return 1;
        return jumpFloorII(number - 1) * 2;
    }
};

int main(){
    Solution s;
    Solution2 s2;
    int t;
    while(true){
        cin>>t;
        cout<<s.jumpFloorII(t)<<endl;
        cout<<s2.jumpFloorII(t)<<endl;
    }
    return 0;
}