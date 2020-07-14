#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int FindGreatestSumOfSubArray(vector<int> array){
        int answer = array[0];
        int result = array[0];
        int end,n = array.size();
        for(end = 1;end < n;end++){
            if(result > 0){
                result += array[end];
            }
            else{
                result = array[end];
            }
            if(answer < result){
                answer = result ;
            }
        }
        return answer;
    }
};

int main(){
    vector<int> v = {6,-3,-2,7,-15,1,2,2};
    Solution s;
    cout<<s.FindGreatestSumOfSubArray(v);
    return 0;
}