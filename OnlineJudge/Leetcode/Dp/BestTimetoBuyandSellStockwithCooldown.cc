// Best Time to Buy and Sell Stock with Cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
 rest[i] = sell[i-1] 因为冷冻期   
 buy[i]  = max(sell[i-2] - price, buy[i-1]) 
 sell[i] = max(buy[i-1] + price, sell[i-1])
 并且 i只由i-1,i-2决定
*/ 
    int maxProfit(vector<int>& prices) {
        long long int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
        for(int price : prices){
            pre_buy = buy;
            buy = max(pre_sell - price, pre_buy);
            pre_sell = sell;
            sell = max(pre_buy + price, pre_sell);
        }
        return sell;
    }
};

/*
day 0              init
               /    |    \
day 1     hold    buy   sell
          /  |   \
day 2  hold   buy  sell ....

以上就是对应的决策树，暴力解法就是使用dfs/bfs搜索
*/


/*
dynamic programming

hold[i] ==> 这天的动作是`持有`,动作结束之后今天的结果是hold[i],其他函数同理

init rest[0] = sold[0] = 0, hold[0] = -inf

hold[i] = max(hold[i-1],rest[i]-prices[i])
sold[i] = hold[i-1] + prices[i]
rest[i] = max(rest[i-1],sold[i-1])

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if(m < 2){
            return 0;
        }
        vector<vector<int>> dp(3,vector<int>(m+1,0));
        dp[0][0] = INT_MIN;

        for(int i = 1;i <= m;i++){
            dp[0][i] = max(dp[0][i-1],dp[2][i-1]-prices[i-1]); // hold
            dp[1][i] = dp[0][i-1]+prices[i-1]; // sold
            dp[2][i] = max(dp[2][i-1],dp[1][i-1]); // rest
        }

        for(int i = 0;i < 3;i++){
            for(int j = 0;j < dp[0].size();j++){
                cout<<setw(10)<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return max(dp[1][m],dp[2][m]);
    }
};