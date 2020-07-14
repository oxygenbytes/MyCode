#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int GetUglyNumber_Solution(int index){
        if(index <= 0)
            return 0;
        int a[index];
        a[0] = 1;
        int j=0,k=0,l=0;
        for(int i = 1;i < index;i++){
            a[i]=min(min(a[j]*2,a[k]*3),a[l]*5);
            if(a[i] == a[j]*2)
                j++;
            if(a[i] == a[k]*3)
                k++;
            if(a[i] == a[l]*5)  
                l++;
        }
        return a[index-1];
    }
};

int main(){
    Solution s;
    cout<<s.GetUglyNumber_Solution(12);
    return 0;
}