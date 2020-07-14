// c程序设计进阶 递归计算逆波兰表达式
// 逆波兰表达式本身的定义就是递归的，如果开头读到一个运算符p，因为四个运算符都是双目运算符
// 那么说明该运算符的后面必定跟着两个逆波兰表达式，且满足（ ）p ()
#include <bits/stdc++.h>
using namespace std;

double notation(){
    char str[20];
    cin>>str;
    switch(str[0])   {
        
        case '+': return notation() + notation();
        case '-': return notation() - notation();
        case '*': return notation() * notation();
        case '/': return notation() / notation();
        default: return atof(str);
    }
}

int main(){
    cout<<notation();
    return 0;
}