#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long nums = 0;
    int InversePairs(vector<int> data){
        vector<int> temp = data;
        Msort(data,temp,0,data.size()-1);
        return nums % 1000000007;
    }
    void Merge(vector<int> &data,vector<int> &temp,int begin,int mid,int end){
        int start = begin;
        int left = begin;
        int right = mid + 1;
        while(left<=mid && right <= end)
        {
            if(data[left] < data[right]){
                temp[begin++] = data[left++];
            }
            else{
                temp[begin++] = data[right++];
                nums += mid - left + 1;
            }
        }
        while(left <= mid){
                temp[begin++] = data[left++];
            }
        while(right<=mid){
                temp[begin++] = data[right++];
            }
        while(start <= end){
                data[start] = temp[start];
                start++;
            } // 因为这个函数没有设计结束标志，故有此设计
    }
    void Msort(vector<int> &data,vector<int> &temp,int begin,int end){
        int mid;
        if(begin < end){
            mid = (begin + end) / 2;
            Msort(data,temp,begin,mid);
            Msort(data,temp,mid+1,end);
            Merge(data,temp,begin,mid,end);
        }
    }
};

int main(){
    vector<int> v = {1,2,3,4,5,6,7,0};
    Solution s;
    cout<<s.InversePairs(v);
    return 0;
}