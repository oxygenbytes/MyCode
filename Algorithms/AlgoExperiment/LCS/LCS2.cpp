#include <bits/stdc++.h>
using namespace std;

string lcs(string str1,string str2,int len1,int len2,string **s){
    if(len1 == 0 || len2 == 0)
        return "";
    string result;
    if(s[len1][len2] != "")
        return s[len1][len2];
    if(str1[len1-1] == str2[len2-1])
        return lcs(str1,str2,len1-1,len2-1,s) + str1[len1-1];
    else{
        string a = lcs(str1,str2,len1-1,len2,s);
        string b = lcs(str1,str2,len1,len2-1,s);
        result = a.length() > b.length() ? a : b;
    }
    s[len1][len2] = result;
    return result;

}
string Lcs(string str1,string str2){
    int len1 = str1.length(),len2=str2.length();
    string **s = new string*[len1+1];
    for(int i = 0;i < len1+1;i++)
        s[i] = new string[len2+1];
    for(int i = 0;i < len1+1;i++)
        for(int j = 0;j < len2+1;j++)
            s[i][j] = "";
    string result = lcs(str1,str2,len1,len2,s);
    // for(int i =0;i< len1+1;i++)
    // {    for(int j = 0;j < len2+1;j++)
    //         cout<<s[i][j]<<" ";
    //     cout<<endl;
    // }
    return result;
}

int main(){
    string str1 = "abcddab";
    string str2 = "bdcaba";
    cout<<Lcs(str1,str2)<<" "<<Lcs(str1,str2).length()<<endl;
    return 0;
}