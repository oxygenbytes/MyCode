// maxInWindows

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        int m = num.size();
        vector<int> res;
        if(size > m || size == 0)
            return res;
        int i = 0,j = size - 1;
        int max = *max_element(num.begin()+i,num.begin() + j+1);
        res.push_back(max);
        i++;j++;
        while(j < m){
            if(num[j] >= max){
                max = num[j];
            }
            else if(num[i-1] >= max){
                max = *max_element(num.begin()+i,num.begin()+j+1);
            }
            res.push_back(max);
            i++;j++;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {2,3,4,2,6,2,5,1};
    Solution s;
    vector<int> res;
    res = s.maxInWindows(nums,3);
    for(int i = 0;i < res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}