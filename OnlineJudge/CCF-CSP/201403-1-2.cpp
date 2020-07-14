#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,int> m;
    //map<int,int> m;
    int n,v,sum=0;
    // 此时，查找的目标是一系列的数，所以数作为键
    // 数的频率作为值
    // 注意map内部的元素是有序的，可以按照顺序输出
    // unorder_map内部元素无序，但是查找非常快
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>v;
        if(m.find(-v) == m.end())
            m[v] = 1;
        else
            sum++;
    }
    cout<<sum;
}