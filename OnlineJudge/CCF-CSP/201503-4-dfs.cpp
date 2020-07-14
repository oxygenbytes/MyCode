#include <bits/stdc++.h>
using namespace std;

#define MAX 20010
vector<int> G[MAX];
bool visit[MAX];
int s;
stack<int> stack1;
int result;
void DFS(int u,int cost){
    visit[u] = 1;
    if(result < cost){
        result = cost;
        s = u;
    }
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i];
        if(!visit[v]){
            DFS(v,cost+1);
        }
    }
}

void Dfs(int u){
    visit[u] = 1;
    while(!stack1.empty())
        stack1.pop();
    stack1.push(u);
    while(!stack1.empty()){
        int u = stack1.top();
        stack1.pop();
        for(int i = 0;i < G[u].size();i++){
            int v = G[u][i];
            if(!visit[v]){
                visit[v] = 1;
                // do something
                // cout<<"v"<<v<<" ";
                stack1.push(v);
            }
        }
    }
    
}
int main(){
    int n,m;
    cin>>n>>m;
    int a;
    for(int i =2;i <= n;i++){
        cin>>a;
        G[i].push_back(a);
        G[a].push_back(i);
    }
    for(int i = 1;i <= m;i++){
        cin>>a;
        G[n+i].push_back(a);
        G[a].push_back(n+i);
    }
    // result = -1;
    // memset(visit,0,sizeof(visit));
    // DFS(1,0);
    // memset(visit,0,sizeof(visit));
    // result = -1;
    // DFS(s,0);
    // cout<<result<<endl;
    Dfs(1);
    return 0;
}