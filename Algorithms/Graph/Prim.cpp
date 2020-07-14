#include <bits/stdc++.h>
using namespace std;

const int n = 6;
const int MAX = 100;

typedef struct 
{
    int lowcost; // 最小边的权值
    int adjvex; // 最小边的起始点 
} Element;

void Prim(int arc[n][n],int start);

int main( )
{
    int m = n; // m是列，n是行
    int arc[n][n] = {
        {MAX, 34 , 46 , MAX, MAX, 19 },
        {34 , MAX, MAX, MAX, 12 , MAX},
        {46 , MAX, MAX, 17 , MAX, 25 },
        {MAX, MAX, 17 , MAX, 38 , 25 },
        {MAX, 12 , 38 , MAX, MAX, 26 },
        {19 , MAX, 25 , 25 , 26 , MAX}
    };
    Prim(arc, 0);

    return 0;
}

// Prim算法的实质可以从集合角度考虑，将结果状态用集合表示,故该算法是一个填充结果集合的过程
// 当某个点被加入结果集合后，那么这个点到这个集合的距离就被标记为0，同时应该更新不属于该集合的节点到目标集合的状态
void Prim(int arc[n][n],int start){
    int min;
    Element shortEdge[10];
    for(int i = 0;i < n;i++) { // 初始化辅助数组
        shortEdge[i].lowcost = arc[start][i];
        shortEdge[i].adjvex = start;
    }
    shortEdge[start].lowcost = 0;
    int k;
    for(int i = 0;i < n-1;i++) { // 边的个数就是n-1
        min = 100;
        
        for(int j = 0;j < n;j++) { // 选出某个点加入结果集合
            if((shortEdge[j].lowcost != 0) && (shortEdge[j].lowcost < min)) {
                min = shortEdge[j].lowcost;
                k = j;
            }
        }

        cout<<shortEdge[k].adjvex<<"--"<<k<<endl;
        shortEdge[k].lowcost = 0;
        
        for(int j = 0;j < n;j++) // 更新不属于目标集合的点到该集合的距离
        {
            if(arc[k][j] < shortEdge[j].lowcost){
                shortEdge[j].lowcost = arc[k][j];
                shortEdge[j].adjvex = k;
            }
        }
    }
}