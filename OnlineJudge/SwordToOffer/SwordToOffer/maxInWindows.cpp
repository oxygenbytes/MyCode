#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size){
        vector<int> re;
        if(num.size() <= 0 || size > num.size()||size<=0) return re;
        int n = num.size() + 1 - size;
        for(int i = 0;i < n;i++){
            vector<int> tem;
            int max = num[i];
            for(int j = i;j < i + size; ++j)
            {
                tmp.push_back(num[j]);
                if(num[j] > max) max = num[j];
            }
            re.push_back(max);
        }
        return re;
    }
}