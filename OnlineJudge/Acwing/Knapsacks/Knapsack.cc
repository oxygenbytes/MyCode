// 01背包问题
// https://www.acwing.com/problem/content/2/
#include <bits/stdc++.h>
using namespace std;

const int N = 6;

int n,m;
int v[N],w[N];

int f[N][N];

int main(){
    cin>>n>>m;
    
    for(int i = 1;i <= n;i++) cin>>v[i]>>w[i];
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++){
            f[i][j] = f[i-1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j],f[i-1][j-v[i]] + w[i]);
        }
    }
    // 调试
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<f[n][m]<<endl;
}

