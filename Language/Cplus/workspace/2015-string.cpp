#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    string instr;
    string outstr;
    map<string,string> mv;
    cin>>m>>n;
    cin.get();
    while(m--){
        string line;    //cin和getline()连用，或者getline()前面有换行输入，则多用一个cin.get()函数
        getline(cin,line);
        instr += line + '\n';
    }
    while(n--){
        string var,x;
        cin>>var;
        cin.get(); 
        getline(cin,x);
        mv[var] = x.substr(1,x.size()-2);
    }
    size_t pos,nextpos;
    while((pos=instr.find("{{ "))!= string::npos){  // string处理，find()是非常核心的函数
        nextpos = instr.find(" }}") + 3;
        string var(instr.begin()+pos+3,instr.begin()+nextpos-3);
        outstr += instr.substr(0,pos); // substr(0,pos) ==> [0,pos)
        instr = instr.substr(nextpos);
        string val = mv.count(var)?mv[var]:"";
        outstr += val;
    }
    outstr += instr;
    cout<<outstr;
    return 0;
}