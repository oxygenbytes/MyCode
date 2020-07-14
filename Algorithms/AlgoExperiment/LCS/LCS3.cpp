#include <bits/stdc++.h>
using namespace std;

void LCS_matrix(string str1,string str2,int **dp){
    int len1 = str1.length();
    int len2 = str2.length();
    for(int i = 0;i <= len1;i++)
        dp[i][0] = 0;
    for(int j = 0;j <= len2;j++)
        dp[0][j] = 0;
    for(int i = 1;i <=len1;i++){
        for(int j = 1;j <= len2;j++){
            if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else if(dp[i-1][j] >= dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
            }
            else
                dp[i][j] = dp[i][j-1];
        }
    }
}

string lcs(string str1,string str2){
    int len1 = str1.length();
    int len2 = str1.length();
    int **dp = new int*[len1+1];
    for(int i = 0;i < len1+1;i++)
        dp[i] = new int[len2+1];
    LCS_matrix(str1,str2,dp);
    string result = "";
    while(len1 > 0 && len2 > 0){
        if(str1[len1-1] == str2[len2-1]){
            result = str1[len1-1] + result;
            len1--;len2--;
        }else if(dp[len1-1][len2] < dp[len1][len2-1]) {
            len2--;
        }else{
            len1--;
        }
    }
    return result;
}

int main(){
    string str1 = "abcddab";
    string str2 = "bdcaba";
    cout<<lcs(str1,str2)<<" "<<lcs(str1,str2).length()<<endl;
}