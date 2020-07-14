#include <bits/stdc++.h>
using namespace std;

map<string,int> mcmd; // 用于存储命令手册，也就是存储命令说明，使用map可以快速查找，而且本身规模不打
map<string,string> m; // 用于存储样例命令参数

string nextsplit(string &str){
    // int pos = str.find(" "); 
    size_t pos = str.find(" ");  // find()函数的返回值类型都是size_t类型的，所以这里应该使用size_t
    // find()返回的结果是匹配到的第一个目标字符
    /* find() 不属于 vector 的成员，而存在于算法中，应加上头文件 #include <algorithm>
    string::find 这类型的函数，返回值类型都是 string::size_type (或者写为 size_t 型)
    而 string::size_type 其实是一种 unsigned int 类型。
    find 的结果记录匹配的位置，或者返回一个名为 string::npos 的特殊值，说明查找没有匹配。
    string 类将 npos 定义为保证大于任何有效下标的值。
    string::npos 的值是无符号型类型的，其值是(unsigned int)(-1)，也就是4294967295。*/
    string ans;
    if(pos == string::npos){ // 倘若没有找到空格
        ans = str;
        str = "";
        return ans;
    }
    ans = str.substr(0,pos); // 从0开始，后面pos长度的字符串作为子串
    str = str.substr(pos+1); // 从pos+1开始，一直到字符串的末尾
    return ans;
}

void deal(string str){
    m.clear(); // 清除使用的容器
    nextsplit(str);  // 首先截掉命令，剩下的就是参数
    while(str.size()>0){
        string x = nextsplit(str);
        if(mcmd.count(x+":")>0 && str.size()>0){
            // map.count()函数 如果map中存在，则返回1；不存在，则返回0，无法确定位置
            // map.find()函数，可以返回要查找元素的位置
            string next = nextsplit(str);
            m[x] = next;
            continue;
        }
        if(mcmd.count(x) > 0){
            m[x] = "";
            continue;
        }
        return ;
    }
    return ;
}

int main(){
    int n;
    string cmd;
    cin>>cmd;

    for(size_t i = 0;i < cmd.size();++i){
        if(i < cmd.size()-1 && cmd[i+1]==':'){ // 用于匹配带参数的情况，而:是作为特征值出现的
            mcmd['-'+string(1,cmd[i])+cmd[i+1]] = 1; // string(int n,char c) 使用n个字符c初始化
            i++;
        }
        else{
            mcmd['-' + string(1,cmd[i])] = 1; // 使用map主要是为了快速查找
        }
    }
    cin>>n;
    cin.get();
    for(int i = 1;i <= n;i++){
        string str;
        getline(cin,str);
        /* 
            cin 基本用法
            cin遇到缓冲区中的[enter],[space],[tab]会结束当前输入，并舍弃[enter],[space],[tab]，
            继续下一项输入，当有连续[space],[enter,[tab]会全部舍弃。
         */
        /*
            一参数
            a = cin.get()  或者  cin.get(a) 
            输入字符足够后回车  ，将字符存储到a中  
            与cin不同，cin.get()在缓冲区遇到[enter]，[space]，[tab]不会作为舍弃，而是继续留在缓冲区中
            按照cin.get()函数的执行次数n,读取前n个字符
         */
        /*
            二参数
          cin.get(arrayname,size)  把字符输入到arrayname中，长度不超过size  
          当把大于数组长度的字符串放出char a[arraylength]中，
          系统自动扩张数组a的长度使a能放得下，但是这么做容易产生运行错误
         */
        /*
            三参数
            cin.get(arrayname,size,s)  把数据输入到arrayname字符数组中
            当到达长度size时结束或者遇到字符s时结束    
         */
        /*
            cin.gerline(arrayname,size) 的用法
            cin.getline(arrayname,size,s)用法与cin.get()效果大致相同，但也有些区别
            cin.get(arrayname,size)当遇到[enter]时会结束目前输入，他不会删除缓冲区中的[enter]
            cin.getline(arrayname,size)当遇到[enter]时会结束当前输入，但是会删除缓冲区中的[enter]
            cin.getline(arrayname,size,s)当遇到s时会结束输入，并把s从缓冲区中删除
            cin.get（arrayname,size,s）当遇到s时会结束输入，但不会删除缓冲区中的s
         */
        deal(str);
        cout<<"Case "<<i<<":";
        map<string,string>::iterator it=m.begin(); // map迭代器的使用 it->first,it->second
        while(it != m.end()){ // 这里注意，map本身其内部的元素是有序的
            cout<<" "<<it->first;
            if(it->second != "")
                cout<<" "<<it->second;
            ++it;
        }
        cout<<endl;
    }
    return 0;
}