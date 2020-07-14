#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> printMatrix(vector<vector<int>> & matrix){
        if(matrix.empty())
            return vector<int>();
        vector<int> ret;

        int m = matrix.size() -1;
        int n = matrix[0].size() -1;

        for(int x = 0,y = 0;x<=m && y <= n; x++, y++){
            for(int j=y;j <= n;j++){
                ret.push_back(matrix[x][j]);
           }

           for(int i = x + 1;i <= m;i++){
               ret.push_back(matrix[i][n]);

           }

           for(int j = n - 1; j >= y && x != m;--j){
               ret.push_back(matrix[m][j]);
           }
           
           for(int i = m - 1;i > x && y != n; --i){
               ret.push_back(matrix[i][y]);
           }
           m--;
           n--;
        }
    return ret;
    }
    
};

int main(){
    vector<vector<int>> v;
    vector<int> temp;
    int m,n;
    cin>>m>>n;
    for(int i = 1; i <= m;i++){
        for(int j = 1;j <= n;j++){
            temp.push_back(i*j);
        }
        v.push_back(temp);
        temp.clear();
    }
    Solution s;
    vector<int> ret= s.printMatrix(v);
    for(int i = 0 ; i < ret.size();i++){
        cout<<ret[i]<<" ";
    }
    return 0;
}
