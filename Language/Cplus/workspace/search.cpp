#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>
using namespace std;
 
#define MAX 20010
vector<int>G[MAX]; // 存储图中的邻接关系
queue<int> q; // 辅助队列，用于执行广搜
bool visit[MAX]; // 用于存储访问情况
stack<int> s;
 
void DFS(int start){
    s.push(start);
    while(!s.empty()){
        int u = s.top();
        s.pop();
        visit[u] = 1;
        cout<<"u"<<u<<" ";
        for(int i =G[u].size()-1;i >=0 ;i--){
            int  v = G[u][i];
            if(!visit[v])
            s.push(G[u][i]);
        }
    }
}

void dfs(int start){
    visit[start] = 1;
    cout<<"v"<<start<<" ";
    for(int i = 0;i < G[start].size();i++){
        int v = G[start][i];
        if(!visit[v]){
            visit[v] = 1;
            dfs(v);
        }
    }
}

void BFS(int start){
    q.push(start);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        visit[u] = 1;
        cout<<"u"<<u<<" ";
        for(int i = 0;i < G[u].size();i++){
            int v = G[u][i];
            if(!visit[v]){
                q.push(v);
            }
        }
    }
}

int main(){
    int n,m,i,a;
    cin>>n>>m;
    for(i=2;i<=n;i++){
        cin>>a;
        G[a].push_back(i);
        G[i].push_back(a);
    }
    for(i=1;i<=m;i++){
        cin>>a;
        G[i+n].push_back(a);
        G[a].push_back(i+n);
    }
    // DFS(1);
    // dfs(1);
    // BFS(1);
    return 0;
}