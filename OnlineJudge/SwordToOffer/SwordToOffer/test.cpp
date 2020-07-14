class Solution {
public:
	vector<vector<bool> > flag; //访问标志
    int movingCount(int threshold, int rows, int cols)
    {
        for (int i = 0;i < rows;++i)//没有访问过设置为true
        {
            vector<bool> vec;
            for (int j = 0;j < cols;++j)
            {
                vec.push_back(false);
            }
            flag.push_back(vec);
        }
        return movCount(threshold, rows, cols,0,0);
    }
    
    //此函数为回溯函数
    int movCount(int threshold, int rows, int cols,int i,int j)//访问的是当前的单元
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols || !LegalOrNot(threshold, i, j) || flag[i][j]) return 0;
        flag[i][j] = true;
        return movCount(threshold, rows, cols, i - 1, j) +
            movCount(threshold, rows, cols, i + 1, j) +
            movCount(threshold, rows, cols, i , j-1) +
            movCount(threshold, rows, cols, i , j+1) +1;

    }

    //此函数为来标注该格子是否是合法的，可以允许访问
    bool LegalOrNot(int threshold, int row, int col)
    {
        int num = 0;
        while (row != 0)
        {
            num = num + row % 10;
            row = row / 10;
        }
        while (col != 0)
        {
            num = num + col % 10;
            col = col / 10;
        }
        if (num <= threshold)
            return true;//合法访问
        return false;
    }
};