#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,cnt=1,pre,cur;
    cin>>n>>pre;
    n--;
    while(n--){
        cin>>cur;
        if(pre==cur) continue;
        else{
            pre = cur;
            ++cnt;
        }
    }
    cout<<cnt<<endl;
    return 0;
}