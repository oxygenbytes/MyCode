
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
#define MAX 20010
vector<int>G[MAX];
bool visit[MAX];
int d[MAX];
int result;
int s;
 
void DFS(int u,int cost){
    visit[u] = 1;
    if(result < cost){
        result = cost;
        s = u;
    }
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if(!visit[v]){
            DFS(G[u][i],cost+1);// cost的最终值是从u出发，能够到达的最大深度
            // 不要忘记dfs的本质，不撞南墙不回头+回溯
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
    result = -1;
    memset(visit,0,sizeof(visit));
    DFS(1,0);
    result = -1;
    memset(visit,0,sizeof(visit));
    DFS(s,0);      //s是一次DFS之后最深的点
    cout<<result<<endl;
    return 0;
}