#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        vector<bool> used(strlen(matrix),false);
        for(int i =0;i <rows;i++){
            for(int j = 0;j < cols;j++){
                if(isPath(matrix,rows,cols,i,j,str,0,used))
                    return true;
            }
        }
        return false;
    }
private:
    bool isPath(char* matrix,int rows,int cols,int row,int col,char* str,int len,vector<bool> used){
        if(len == strlen(str))
            return true;
        int idx = row * cols + col; // 只有完全匹配，才会返回true,约束条件用于剪枝
        if(row > rows || col > cols || row < 0 || col < 0 || used[idx] == true || matrix[idx] != str[len])
            return false;
        used[idx] = true;
        bool judge = isPath(matrix,rows,cols,row-1,col,str,len+1,used) ||
                     isPath(matrix,rows,cols,row+1,col,str,len+1,used) ||
                     isPath(matrix,rows,cols,row,col-1,str,len+1,used) ||
                     isPath(matrix,rows,cols,row,col+1,str,len+1,used);
        if(judge == true)
            return true;
        used[idx] = false;
        return false;
    }
};