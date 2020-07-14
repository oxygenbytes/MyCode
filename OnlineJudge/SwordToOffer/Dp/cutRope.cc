// cutRope

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cutRope(int number) {
        if(number == 2) return 1;
        if(number == 3) return 2;
        if(number == 4) return 4;
        int p,q;
        p = number / 3;
        q = number % 3;
        
        if(q == 0)
            return pow(3,p);
        else if(q == 1)
            return pow(3,p-1) * 4;
        else 
            return pow(3,p) * 2;
    }
};