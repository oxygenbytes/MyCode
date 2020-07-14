// Count and Say
// https://leetcode.com/problems/count-and-say/
// bytedance 2020.6.28 提前批第二次笔试

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0) return "";
        string str = "1";
        while(n--){
            string cur = "";
            for(int i = 0;i < str.size();i++){
                int cnt = 1;
                while(i+1 < str.size() && str[i] == str[i+1]){
                    ++cnt;
                    ++i;
                }
                cur += to_string(cnt) + str[i];
            }
            str = cur;
        }
        return str;
    }
};
/*
这道题没做出来，为什么，第一个，没有想好程序的输入和输出
第二个就是没有理清楚程序运行的两个流程，第一个就是n，第二个就是由str => cur（n-1 => n)
*/
