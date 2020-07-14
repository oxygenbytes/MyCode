#include <bits/stdc++.h>
using namespace std;

string lcs(string str1,string str2,int len1,int len2){
    string a,b;
    if(len1 < 0 || len2 < 0)
        return "";
    if(str1[len1] == str2[len2]) {
        return lcs(str1,str2,len1-1,len2-1)+str1[len1];
    }
    a = lcs(str1,str2,len1-1,len2);
    b = lcs(str1,str2,len1,len2-1);
    return a.length() > b.length() ? a : b;
}

int main(){
    string str1 = "ababacb";
    string str2 = "aabac";
    int len1 = str1.length();
    int len2 = str2.length();
    string result = lcs(str1,str2,len1-1,len1-1);
    cout<<result<<" "<<result.length();
    return 0;
}