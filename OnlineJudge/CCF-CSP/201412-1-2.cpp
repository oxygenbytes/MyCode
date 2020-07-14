#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int,int> mp;
    vector<int> v;
    for(int i = 0;i < n;i++){
        int temp;
        cin>>temp;
        if(mp.find(temp) != mp.end())   mp[temp]++;
        else mp[temp] = 1;
        v.push_back(mp[temp]);
    }

    for(int i = 0;i < v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;

}