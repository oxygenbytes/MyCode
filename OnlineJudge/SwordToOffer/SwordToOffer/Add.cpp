#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int Add(int num1,int num2){
        while(num2!=0){
            // 不要考虑所有的位，只要考虑当前最低位
            int temp = num1^num2; // 异或操作，不同为1，相同为0
            num2 = (num1 & num2) << 1; // 从最低位开始向上进位
            // cout<<bitset<sizeof(int)*8>(num1)<<endl;
            cout<<bitset<sizeof(int)*8>(num2)<<endl;
            num1 = temp;
        }
        return num1;
    }
};

int main(){
    Solution s;
    // cout<<s.Add(12,23);
    cout<<bitset<sizeof(int)*8>(12)<<endl;
    cout<<bitset<sizeof(int)*8>(23)<<endl;
    return 0;
}