#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int NumberOf1Between1AndN_Solution(int n){
        int number = 0;
        for(int i =1;i <=n;i++){
            number += getNumber(i);
        }
        return number;
    }
    int getNumber(int n){
        int number = 0;
        while(n){
            if(n % 10 == 1){
                number ++;
            }
            n = n / 10;
        }
        return number;
    }
};

int main(){
    Solution s;
    int temp = s.NumberOf1Between1AndN_Solution(13);
    cout<<temp<<endl;
    return 0;
}