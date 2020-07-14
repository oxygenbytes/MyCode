// hasPath

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        visited = vector<vector<bool>>(rows, vector<bool>(cols,false));
        for(int row = 0;row < rows; row++){
            for(int col = 0;col < cols;col++){
                if(matrix[row * cols + col] == str[0]){
                    if(dfs(row,col,rows,cols,str,0,matrix,visited))
                        return true;
                }
            }
        }
        return false;
    }
private:
    vector<vector<bool>> visited;
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(int x,int y, int rows, int cols,char* str,int len,char* matrix, vector<vector<bool>>& visited){
        if(len == strlen(str))
            return true;
        
        //  cout<<x<<" "<<y<<" "<<str<<endl;
        if(x >= rows || y >= cols || y < 0 || x < 0 || visited[x][y] == true || matrix[x * cols + y] != str[len])
            return false;
        visited[x][y] = true;
        bool judge;
        for(int i = 0;i < 4;i++){
            int xx = x + dir[i][0];
            int yy = y + dir[i][1];
            judge = dfs(xx,yy,rows,cols,str,len+1,matrix,visited);
            if(judge == true)
                break;
        }
        if(judge == true)
            return true;
        visited[x][y] = false;
        return false;
    }
};

int main(){
    char* matrix = "abcesfcsadee";
    Solution s;
    // cout<<s.hasPath(matrix,3,4,"bcced")<<endl;
    cout<<s.hasPath(matrix,3,4,"abcb")<<endl;
    return 0;
}