#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input,int k){
        vector<int> result;
        int len = input.size();
        if(input.empty() || k <= 0 || len < k) return result;

        multiset<int,greater<int>> leastNumber;
        multiset<int,greater<int>>::iterator iterGreater;

        vector<int>::iterator iter = input.begin();
        for(;iter != input.end();++iter){
            if(leastNumber.size() < k){ // 注意此处的临界条件
                leastNumber.insert(*iter);
            }
            else{
                iterGreater = leastNumber.begin();

                if(*iter < *(leastNumber.begin())){
                    leastNumber.erase(iterGreater);
                    leastNumber.insert(*iter);
                }
            }
        }

        for(iterGreater = leastNumber.begin();iterGreater!=leastNumber.end();++iterGreater){
            result.push_back(*iterGreater);
        }
        return result;
    }
};

int main(){
    vector<int> v = {4,5,1,6,2,7,3,8};
    Solution s;
    vector<int> result = s.GetLeastNumbers_Solution(v,4);
    for(int i = 0;i < result.size();i++)
        cout<<result[i]<<" ";
    cout<<endl;
    return 0;

}