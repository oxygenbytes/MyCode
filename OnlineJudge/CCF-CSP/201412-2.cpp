#include <bits/stdc++.h>
using namespace std;

int n;
int k=0;
int a[512][512];

vector<int> v[1024];

void help(int i,int j,int k){
    while(i>=0&&i<n&&j>=0&&j<n)
        v[k].push_back(a[i++][j--]);
}

void ser(){
    for(int j = 0;j < n;j++){ // 处理上三角
        help(0,j,k++);
    }
    for(int i=1;i < n;i++) // 处理下三角
        help(i,n-1,k++);
}

int main(){
    cin>>n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j <n;j++){
            cin>>a[i][j];
        }
    }

    ser();

    for(int i = 0;i < k;i++){
        if(i%2){
            // cout<<"2* ";
            for(size_t j=0;j<v[i].size();++j)
                cout<<v[i][j]<<" ";
            // cout<<endl;
        }
        else{
            // cout<<"1* ";
            for(int j=v[i].size()-1;j>=0;--j)
                cout<<v[i][j]<<" ";
            // cout<<endl;
        }
    }
    return 0;
}