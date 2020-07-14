#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void fun(string &s,int start,int end){
        char temp;
        while(start < end){
            temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start ++;
            end --;
        }
    }
    string LeftRotateString(string str,int n){
        int len = str.length();
        if( 0 == len || 0 == n)
            return str;
        string &temp = str;
        fun(temp,0,n-1); //先反转前[0,n-1]
        fun(temp,n,len-1); //再反转后[n,len-1]
        fun(temp,0,len-1); //对整体反转[0,len-1]
        return str;
    }
};