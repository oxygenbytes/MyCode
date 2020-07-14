#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<bool> > flag;
    int movingCount(int threshold, int rows, int cols)
    {   
        for(int i = 0;i < rows;i++){
            vector<bool> temp;
            for(int j = 0;j < cols;++j){
                temp.push_back(false);
            }
            flag.push_back(temp);
        }
        return movConut(threshold,rows,cols,0,0);
    }
    int movCount(int threshold,int rows,int cols,int row,int col){
        if(row < 0 || col < 0 || row >= rows || col >= cols || !LegalOrNot(threshold,row,col) || flag[row][col])
            return 0;
        flag[row][col] = true;
        return movCount(threshold,rows,cols,row-1,col) +
                 movCount(threshold,rows,cols,row+1,col) +
                 movCount(threshold,rows,cols,row,col-1) +
                 movCount(threshold,rows,cols,row,col+1) +  1;
    }
    // 判断当前格子是否合法
    bool LegalOrNot(int threshold,int row,int col)
    {
        int num = 0;
        while(row != 0){
            num += row % 10;
            row = row / 10;
        }
        while(col != 0){
            num += col%10;
            col = col / 10;
        }
        if(num <= threshold)
            return true;
        return false;
    }
};