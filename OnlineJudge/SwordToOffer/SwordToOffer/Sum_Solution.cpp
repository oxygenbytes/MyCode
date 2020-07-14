#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Sum_Solution(int n) {
        if(n == 1) return n;
        return Sum_Solution(n-1) + n;
    }
};

class Solution2{
public:
    Solution2() {++N;Sum += N;}

    static void Reset() {N = 0;Sum = 0;}
    static unsigned int GetSum() {return Sum;}
private:
    static unsigned int N;
    static unsigned int Sum;
};

int main(){
    Solution s;
    cout<<s.Sum_Solution(10);
    return 0;
}