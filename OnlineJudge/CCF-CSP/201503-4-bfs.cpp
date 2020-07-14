#include <bits/stdc++.h>
using namespace std;

#define MAX 20010
vector<int> G[MAX];
int visit[MAX];
queue<int> q;
int d[MAX];

int BFS(int u,int &position){
    int ans = 0;
    memset(visit,0,sizeof(visit));
    memset(d,0,sizeof(d));
    position = u;
    while(!q.empty())
        q.pop();
    q.push(u);
    visit[u] = 1;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int i =0;i < G[u].size();i++){
            int v = G[u][i];
            if(!visit[v]){
                visit[v] = 1;
                d[v] = d[u] + 1;
                if(d[v] > ans){
                    ans = d[v];
                    position = v;
                }
                q.push(v);
            }

        }
    }
    return ans;
}


int main(){
    int m,n;
    cin>>n>>m;
    int a;
    for(int i = 2;i<=n;i++){
        cin>>a;
        G[i].push_back(a);
        G[a].push_back(i);
    }
    for(int i = 1;i <= m;i++){
        cin>>a;
        G[n+i].push_back(a);
        G[a].push_back(n+i);
    }
    int position;
    int ans = BFS(1,position);
    ans = BFS(position,position);
    cout<<ans<<endl;
    return 0;
}