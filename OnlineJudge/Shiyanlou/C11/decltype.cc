// decltype

#include <bits/stdc++.h>
using namespace std;
/*
decltype(表达式)
copy
在此过程中，编译器分析表达式并得到它的类型，却不实际计算表达式的值。
*/

int main(){
    auto x = 1;
    auto y = 2;
    decltype(x+y) z;  // 自动推导x+y的类型，并将z的类型指定为推导的类型
    z = 12;
    cout<<z<<endl;
    return 0;
}
