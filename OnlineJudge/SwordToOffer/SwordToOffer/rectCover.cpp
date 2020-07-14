#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
        if(number == 1 ) return 1;
        if(number == 2 ) return 2;
        int first = 1;
        int second = 2;
        int temp;
        for(int i = 3; i <= number; i++){
             temp = first;
             first = second;
             second = temp + second;
        }
        return second;
    }
};

int main(){
    Solution s;
    cout<<s.rectCover(30);
    return 0;
}