#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> FindContinuousSequence(int sum){
        vector<vector<int>> res;
        if(sum < 3) return res;
        int i = 1, j = 2, mid = (sum + 1) / 2,cur = i + j;
        while(i < j && j <= mid){
            if(cur == sum){
                vector<int> ares;
                for(int k = i;k <=j;k++){
                    ares.push_back(k);
                }
                res.push_back(ares);
                cur += ++j;
            }
            else if(cur < sum){
                cur += ++j;
            }
            else{
                cur -= i++;
            }
                
        }
        return res;
    }
};

int main(){
    vector<vector<int>> v;
    Solution s;
    v = s.FindContinuousSequence(9);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}