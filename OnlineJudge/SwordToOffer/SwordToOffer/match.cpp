#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool match(char *str,char* pattern){
        if(*str == '\0'){
            if(*pattern == '\0' || (*(pattern+1)=='*' && *(pattern+2)=='\0'))
                return true;
            else
                return false;
        }
        if(*(pattern)=='\0')
            return false;
        if(*(pattern+1)=='*'){
            if(*pattern==*str||*pattern=='.')
                return match(str+1,pattern) || match(str,pattern+2);
            else return match(str,pattern+2);
        }
        if(*pattern == *str || *pattern == '.'){
            return match(str+1,pattern+1);
        }
        return false;
    }
};

int main(){
    char str1[10] = "aaa";
    char str2[10] = "a.a";
    Solution s;
    cout<<s.match(str1,str2);
    return 0;
}