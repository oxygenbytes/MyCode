#include <bits/stdc++.h>
using namespace std;

class  Solution{
public:
    int GetNumberOfK(vector<int> data,int k){
        int lower = getLower(data,k);
        int higher = getHigher(data,k);
        if(higher >= data.size() || lower == -1)    return 0;
        return higher - lower + 1;
    }
    int getLower(vector<int> data,int k){
        int mid,left = 0;
        int right = data.size() - 1;
        while(left <= right){
            mid = left +((right - left) >> 1);
            if(data[mid] < k) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
    int getHigher(vector<int> data,int k){
        int mid,left = 0;
        int right = data.size() - 1;
        while(left <= right){
            mid = left + ((right - left) >> 1);
            if(data[mid] <= k) left = mid + 1;  // 这里体现了等号的作用，寻找最右面的元素
            else right = mid - 1;
        }
        return right;
    }
};

int main(){
    //  有序序列，二分搜索
    vector<int> v = {1,2,2,2,3,4,5,6};
    Solution s;
    cout<<s.GetNumberOfK(v,2);
    return 0;
}