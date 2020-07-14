#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int cutRope(int number) {
        if(number == 2)
            return 1;
        if(number == 3)
            return 2;
        int total3 = 0,total2 = 0;

        total3 = number / 3;

        if(number - total3*3 == 1)
            total3 -= 1;
        total2 = (number - total3*3)/2;
        cout<<total2<<" "<<total3<<endl;
        return (int)(pow(2,total2)) * (int)pow(3,total3);
    }
};

class Solution {
public:
    int cutRope(int number){
        if(number == 2)
            return 1;
        if(number == 3)
            return 2;
        int max = 0;
        int f[number+1];
        f[0] = 0; // 注意：割的时候，情况与返回时不同，因为返回时必须割一刀
        f[1] = 1;
        f[2] = 2;
        f[3] = 3;
        for(int i = 4;i <= number;i++){
            max = 0;
            for(int j = 1;j <= i / 2;j++){
                int temp = f[j] * f[i-j];
                if(max < temp)
                    max = temp;
            }
            f[i] = max;
        }
        max = f[number];
        return max;
    }
};
int main(){
    Solution s;
    cout<<s.cutRope(8);
    return 0;
}