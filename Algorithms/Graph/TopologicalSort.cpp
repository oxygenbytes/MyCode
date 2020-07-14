#include <bits/stdc++.h>
using namespace std;
// 代码的核心是，是维持一个入度为 0 的顶点。

bool TopSort(vector<vector<int>> &G,int n,vector<int> &inDegree){
    int num = 0;
    queue<int> q;
    for(int i = 0;i < n;i++){
        if(inDegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        cout<<"u"<<u<<" ";
        q.pop();
        for(int i = 0;i < G[u].size();i++){
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0)
                q.push(v);
        }
        G[u].clear();
        num++;
    }
    if(num == n)
        return true;
    else return false;
}
int main(){
    int n,m;
    cout<<"please input vertex and edge:";
    cin>>n>>m;

    vector<vector<int>> G(n);
    for(int i = 0;i < m;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);//因为这是有向图，所以邻接表有序
    }
    cout<<"topological sort:"<<endl;
    vector<int> inDegree(n);
    for(auto x : G){
        for(auto y : x)
            inDegree[y]++;
    }
    bool res = TopSort(G,n,inDegree);
    return 0;
}