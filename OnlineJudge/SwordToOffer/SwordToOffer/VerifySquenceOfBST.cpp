#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        bool rst;
        rst = verify(sequence,0,sequence.size()-1);
        return rst;
    }
    bool verify(vector<int> sequence,int start,int end){
        if(start > end) 
        // 此处start和end并不是树的节点，而是vector中的键，因为是递归，所以start > end是结束条件
            return true;
        
        int i ;
        for(i = start;i<end;i++){
            if(sequence[i] > sequence[end])
                break;
        }
        int pivot = i;
        for(i;i<end;i++){
            if(sequence[i] < sequence[end])
                return false;
        }
        return verify(sequence,start,pivot-1) && verify(sequence,pivot,end-1);
    }
};

int main(){
    vector<int> v = {5,7,6,9,11,10,8};
    Solution s;
    cout<<s.VerifySquenceOfBST(v);
    cout<<endl;
    cout<<true;
    return 0;
}