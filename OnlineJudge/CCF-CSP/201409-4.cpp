#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node{ // 描述分店的人到达某个点时的状态
    int x,y;
    ll distance;
    node(int a,int b,ll dis):x(a),y(b),distance(dis){ 
    // distance就是第一个到达当前点的分店店员走过的路程
    }
};
queue<node> q;
int posNum[1024][1024];
bool visit[1024][1024]; // 如果某个点有标记，说明这个点已经有其他分店的人来过，意味着这里的问题已经解决

int dx[] = {1,0,-1,0}; // 注意，如何来描述从某个点向上，向下，向左，向右
int dy[] = {0,1,0,-1};
int n,k,m,d;

bool islegal(int x,int y){
    return x>=1 && x <= n && y >= 1 && y <=n;
}

int main(){
    cin>>n>>k>>m>>d;
    for(int i =0;i <k;i++){
        int x,y;
        cin>>x>>y;
        q.push(node(x,y,0));
        visit[x][y]=1;
    }
    for(int i=0;i < m;i++){
        int x,y,nums;
        cin>>x>>y>>nums;
        posNum[x][y]=nums;
    }
    for(int i=0;i<d;++i){
        int x,y;
        cin>>x>>y;
        visit[x][y] = 1;
    }
    ll ret = 0;
    while(!q.empty()){ // bfs 广度优先搜索
        node cur = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            int x = cur.x + dx[i],y = cur.y + dy[i],dis=cur.distance;
            if(islegal(x,y) && !visit[x][y]){
                ret += posNum[x][y] * (dis + 1);
                visit[x][y] = 1;
                q.push(node(x,y,dis+1));
            }
        }
    }
    cout<<ret;
    return 0;
}