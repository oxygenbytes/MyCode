#include <bits/stdc++.h>
using namespace std;

int main(){
    string x;
    int tag,n;
    cin>>x>>tag>>n;
    while(n--){
        string str;
        cin>>str;
        if(tag==1){ // 默认情况下find查找就是区分大小写的
            size_t pos = str.find(x);
            if(pos!=string::npos){
                cout<<str<<endl;
            }
        }
        else{ // 倘若不区分大小写，那么将目标字符串和待匹配字符串都变成小写即可
            string temp,tx;
            for(size_t i=0;i <str.size();++i){
                temp+=tolower(str[i]);
            }
            for(size_t i = 0;i <x.size();++i){
                tx+=tolower(x[i]);
            }
            size_t pos = temp.find(tx);
            if(pos!=string::npos){
                cout<<str<<endl;
            }
        }
    }
    return 0;
    
}