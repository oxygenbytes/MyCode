#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int m = rotateArray.size() - 1;
        if(m == -1)
            return 0;
        int n = 0;
        int  mid ;
        while(n < m){
            mid = (m + n) / 2;
            if(rotateArray[n] < rotateArray[m])
            {
                return rotateArray[n];
            }
        
            if(rotateArray[n] == rotateArray[m] && rotateArray[n] == rotateArray[mid]){
                return MinOrder(rotateArray,n,m);
            }//if
            if(rotateArray[n] < rotateArray[mid])
                n = mid + 1;
            else
                m = mid ;

        }
        return rotateArray[n];
    }
private:
    // 顺序寻找最小值
    int MinOrder(vector<int> &num,int left,int right){
        int result = num[left];
        for(int i = left + 1;i < right;++i){
            if(num[i] < result){
                result = num[i];
            }//if
        }//for
        return result;
    }

};



int main(){
    vector<int> rotateArray = {2,1,2,2,2,2,2};
    Solution solution ;
    cout<<solution.minNumberInRotateArray(rotateArray);
    return 0;
}