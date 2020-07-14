// Is Subsequence
// https://leetcode.com/problems/is-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i < t.size()){
            if(s[j] == t[i])
                j++;
            i++;
        }
        // cout<<i<<" "<<j<<endl;
        return j == s.size();
    }
};