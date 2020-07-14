// movingCount

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int movingCount(int threshold, int rows, int cols)
    {
        visited = vector<vector<bool>>(rows,vector<bool>(cols,false));
        if(threshold > 0)
            dfs(threshold,0,0,rows,cols);
        return result;
    }
    void dfs(int threshold,int x,int y,int rows,int cols){
        visited[x][y] = true;
        result++;
        for(int i = 0;i < 4;i++){
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            if(judge(threshold,xx,yy,rows,cols))
                if(!visited[xx][yy])
                    dfs(threshold,xx,yy,rows,cols);
        }
        
    }
private:
    int result = 0;
    vector<vector<bool>> visited;
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
     bool judge(int threshold, int x, int y,int rows,int cols){
         int sum = 0;
         int xx = x, yy = y;
         while(x > 0){
             sum += x % 10;
             x /= 10;
         }
         while(y > 0){
             sum += y % 10;
             y /= 10;
         }    
         return threshold >= sum && rows > xx && 0 <= xx && cols > yy && 0 <= yy;
     }
};

int main(){
    Solution s;
    cout<<s.movingCount(18,40,40)<<endl;
    return 0;
}