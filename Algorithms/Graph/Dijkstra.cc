// dijkstra算法的实现，使用了优先队列的数据结构，思路见笔记
#include <bits/stdc++.h>
using namespace std;
/*
    1 优先队列的使用方法
    2 Dijkstra算法中数据结构的组织，一个是图，一个是距离向量，因为使用了优先队列的数据结构，因此不需要对
      图节点的访问情况再做记录，优先队列中元素的状态本身就可以判断图节点的访问情况
*/
#define INF 10000001
vector<pair<int,int> > graph[100];
int dis[100];

void dij(vector<pair<int, int> > *v , int s , int *dis){
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    pq.push(make_pair(0,s));
    dis[s] = 0;
    int u;
    while(!pq.empty()){
        u = (pq.top()).second;
        pq.pop();
        for(vector<pair<int,int>>::iterator it = v[u].begin();it!=v[u].end();it++){
            if(dis[u] + it->first < dis[it->second]){
                dis[it->second] = dis[u] + it->first;
                pq.push(make_pair(dis[it->second],it->second));
            }
        }
    }
}

int main(){
    int m,n,l,x,y,s;
    // n number of node ; m number of edge
    cin>>n>>m;
    for(int i = 0;i < m;i++){
        scanf("%d%d%d",&x,&y,&l);
        graph[x].push_back(make_pair(l,y));
        graph[y].push_back(make_pair(l,x));
    }

    scanf("%d",&s);

    for(int i = 1;i <= n;i++){
        dis[i] = INF;
    }
    dij(graph,s,dis);
    for (int i = 1; i <= n; i++)
        if (dis[i] == INF)
            cout << "-1 ";
        else
            cout << dis[i] << " ";
    return 0;
}

/*
5 6
1 2 7
1 3 2
2 4 2
3 4 4
4 5 1
1 5 5
1
*/