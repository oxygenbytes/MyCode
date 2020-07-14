#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //不稳定，奇数偶数的相对顺序会改变
    void reOrderArray(vector<int> &array) {
        int length = array.size();
        if(length == 0)
            return ;
        int first = 0, last = length - 1;
        while(first < last){
            while((array[first] & 0x1) != 0)
             first ++;
            while((array[last] & 0x1) == 0)
             last --;
            swap(array[first],array[last]);
        }
    }
    void reOrderArrayStable(vector<int> &array){
        int length = array.size();
        for(int i = 0;i < length;i++){
            for(int j = 0;j < length - i - 1;j++){
                if((array[j] & 0x1) == 0 && (array[j+1] & 0x1) != 0)
                    swap(array[j],array[j+1]);
            }
        }
    }
};
int main(){
    vector<int> v;
    for(int i = 0; i < 50 ; i += 3)
        v.push_back(i);
    for(int k : v)
        cout<<k<<" ";
    cout<<endl;
    Solution s;
    s.reOrderArrayStable(v);
    for(int k : v)
        cout<<k<<" ";
        cout<<endl;
    return 0;
}