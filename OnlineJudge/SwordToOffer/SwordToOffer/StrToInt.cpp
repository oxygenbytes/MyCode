#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int StrToInt(string str){
        int n = str.size(),s=1;
        long long res =0;
        if(!n) return 0;
        if(str[0] == '-') s =-1;
        for(int i = (str[0] =='-' || str[0] == '+') ? 1 : 0;i < n;i++){
            if(!('0' <= str[i] && str[i] <= '9')) return 0;
            res = (res<<1) + (res<< 3) + (str[i] & 0xf); // 注意 << 符号的优先级低于+-
        }
        return s * res;
    }
};

int main(){
    string s0 = "+2147483647";
    string s1 = "1a33";
    Solution s;
    cout<<s.StrToInt(s0)<<endl;
    cout<<s.StrToInt(s1)<<endl;
    return 0;
}