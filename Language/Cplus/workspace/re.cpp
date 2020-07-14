#include <vector>
#include <string>
#include <iostream>
#include <regex>
using namespace std;

void judge_mobile(){
    //regex_match
    // 返回值,匹配成功返回1，失败返回0
    // 注意:这种匹配是整个字符串完全匹配的
    string mobile = "18845165226";
    regex re("1\\d{10}");
    if(regex_match(mobile,re)){
        cout<<"it's right!"<<endl;
    }
    else
    {
        cout<<"wrong!"<<endl;
    }
}

void group_match(){
    string str = "this is text string!";
    regex sre("this(.*?)te(.*?)tring!",regex::icase);
    smatch sm;
    regex_match(str,sm,sre);
    for(unsigned i = 0;i < sm.size();i++)
        cout<<"["<<sm[i]<<"] \n";
}
int main(){
    group_match();
    return 0;
    
}