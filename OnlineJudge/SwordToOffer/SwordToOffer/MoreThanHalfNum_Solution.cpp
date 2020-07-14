#include <bits/stdc++.h>
using namespace std;

class Solution{
public: 
    int MoreThanHalfNum_Solution(vector<int> number){
        if(number.empty()) return 0;
        int result = number[0];
        int times = 1;
        for(int i =0;i < number.size();i++){
            if(times == 0){
                result = number[i];
                times = 1;
            }else if(number[i] == result){
                times++;
            }else
            {
                times--;
            }
        }//end for loop 寻找出现次数最多的数
        times = 0;
        for(int i = 0;i<number.size();i++){
            if(number[i] == result) ++times;
        }
        return (times > number.size()/2) ? result : 0;
    }
};

int main(){
    vector<int> v = {1,2,3,2,2,2,5,4,2};
    Solution s;
    cout<<s.MoreThanHalfNum_Solution(v);
    return 0;
}