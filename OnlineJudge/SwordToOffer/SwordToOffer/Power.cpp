#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        if(equal(base, 0.0) && exponent > 0)
            return 0;
        if(exponent < 0)
            return 1 / Power(base, -exponent);

        return goodPower(base,exponent);
        
    }
    bool equal(double num1, double num2){
        if((num1 - num2) > -0.0000001
           && (num1 - num2) < 0.0000001)
            return true;
        else
        {
            return false;
        }
        
    }
    double goodPower(double base,int exponent){
        if(exponent == 0)
            return 1;
        if(exponent == 1)
            return base;
        double result = goodPower(base,exponent >> 1);
        result *= result;
        if(exponent & 1)
         result = result * base;
        return result;
    }
};


int main(){
    Solution s;
    cout<<s.Power(3,4)<<endl;
    return 0;
}