/* ccf-csp
   201403-4
   无线网络
   author:cogitates
*/
#include <bits/stdc++.h>
using namespace std;

struct node{
    int x,y;
    int vertexnum;
    int counts;
    node(int a,int b,int vn,int c):x(a),y(b),vertexnum(vn),counts(c){}
};
vector<node> v;
bool matrix[256][256];
bool visit[256];

bool isConnect(node &a,node &b,int r){
    return (long long)(a.x - b.x)*(a.x-b.x)+(long long)(a.y-b.y)*(a.y-b.y)<=(long long)r*r;
}
int main(){
    int n,m,k,r;
    cin>>n>>m>>k>>r;
    for(int i = 0;i < m+n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back(node(x,y,i,0));
    }// i是节点编号
    for(int i = 0;i < m + n;i++){
        for(int j = 0;j < m + n;j++){
            matrix[i][j] = isConnect(v[i],v[j],r);
        }
    }
    queue<node> q;
    q.push(v[0]);
    int elecnt=1,level=1;
    // 使用广度优先搜索，从节点1出发，根据连通关系，寻找到节点2搜索停止
    while(elecnt>0){ //广搜的结束条件是队列为空
        int nextelecnt=0;
        for(int i = 0;i < elecnt;++i){
            node cur = q.front();
            q.pop();
            if(cur.vertexnum==1){ // 当遍历中心是节点2时，此时程序结束
            // 第一次遍历一定是只有起始点一个，所以level=1时，只是查找1的邻接节点，并入队列
            // 当以其他节点为基准进行广搜时候，此时level至少是2
                cout<<level-2<<endl;
                return 0;
            }
            int w = cur.vertexnum,u=0;//遍历邻接矩阵的某行时，需要的索引
            while(u<m+n){
                if(matrix[w][u] && !visit[u] && cur.counts<=k){
                // 以某节点为中心做遍历时，如果此节点满足要求，并且此节点之前没被访问，那么就将之入队列
                    visit[u] = true; // 更新节点
                    v[u].counts= (u >= n)?cur.counts+1:cur.counts; // 补充节点
                    q.push(v[u]);
                    ++nextelecnt;
                }
                ++u;
            }

        }
        elecnt=nextelecnt;
        ++level;
    }
    return 0;
}