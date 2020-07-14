/*
    201503-4
    网络延迟
    author:cogitates
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> v[20018];

int n,m;
void dfs(int u,int depth,int &maxdepth,int &maxdepvertex,bool visit[]){
    visit[u] = 1;
    if(depth > maxdepth){
        maxdepth = depth;
        maxdepvertex = u;
    }
    for(size_t i = 0;i < v[u].size();i++){
        int w = v[u][i];
        if(!visit[w]) dfs(w,depth+1,maxdepth,maxdepvertex,visit);
    }
}
int main(){
    scanf("%d %d",&m,&n);
    for(int i = 2;i <= n;i++){
        int x;
        scanf("%d",&x);
        v[x].push_back(i);
        v[i].push_back(x);
    }
    for(int i = 1;i <= m;i++){
        int x;
        scanf("%d",&x);
        v[x].push_back(i + 10000);
        v[i + 10000].push_back(x);
    }

    bool v1[20018]={0};
    bool v2[20018]={0};// visit[] ??
    
    int maxdepth=-1;
    int maxdepvertex=-1;
    dfs(1,0,maxdepth,maxdepvertex,v1);
    dfs(maxdepvertex,0,maxdepth,maxdepvertex,v2);
    printf("%d\n",maxdepth);
    return 0;
}