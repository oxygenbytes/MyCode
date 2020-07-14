// auto

#include <bits/stdc++.h>
using namespace std;

// auto 用于对|变量|进行类型推导

int main(){
    map<int,int> mp = {make_pair(1,2),make_pair(2,3)};
    for(map<int,int>::const_iterator itr = mp.cbegin(); itr != mp.cend(); ++itr){
        cout<<itr->first<<" ";
        cout<<itr->second<<endl;
    }
    cout<<"**************************************"<<endl;
    for(auto itr = mp.cbegin(); itr != mp.cend(); ++itr){
        cout<<itr->first<<" ";
        cout<<itr->second<<endl;        
    }
    return 0;
}