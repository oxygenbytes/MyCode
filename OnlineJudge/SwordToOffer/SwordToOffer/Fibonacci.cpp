#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1 || n == 2){
            return 1;
        }
        int v[40];
        v[0] = 0; 
        v[1] = 1;
        v[2] = 1;
        int t = 3;
        while(t <= n){
            v[t] = v[t-1] + v[t-2];
            t++;
        }
        return v[n];
    }
};

int main(){
    Solution solution;
    int n;
    while(true){
        cin>>n;
        cout<<solution.Fibonacci(n)<<endl;
    }
    
}