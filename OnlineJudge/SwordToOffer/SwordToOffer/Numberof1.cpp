#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
         int TotalOne = 0;
         int t = 0;
         int p = 1;
         while(t < 32){
             if(n & p)  
                 TotalOne +=  1;
              p = p << 1;
              t ++;
         }
         return TotalOne;
     }
};

int main(){
    Solution s;
    cout<<s.NumberOf1(127);
    return 0;
}