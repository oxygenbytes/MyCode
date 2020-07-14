#include <bits/stdc++.h>
using namespace std;

/*
弃用的特性（1）：如果一个类有析构函数，为其生成拷贝构造函数和拷贝赋值运算符的特性被弃用了。**

弃用的特性（2）：不再允许字符串字面值常量赋值给一个 char *。如果需要用字符串字面值常量赋值和初始化一个 char *，应该使用 const char * 或者 auto。

弃用的特性（4）：auto_ptr 被弃用，应使用 unique_ptr。

弃用的特性（5）：register 关键字被弃用。

弃用的特性（6）：bool 类型的 ++ 操作被弃用。

弃用的特性（7）：C 语言风格的类型转换被弃用，应该使用 static_cast、reinterpret_cast、const_cast 来进行类型转换。
*/

class Test{
public:
    Test(int a){
        x = a;
    }
    int getX(){
        return x;
    }
    ~Test(){
        cout<<"good"<<endl;
    }
private:
    int x;
};

int main(){
    // 1.
    Test a(12);
    //Test b = a;
    Test b(a);
    cout<<b.getX()<<endl;
    cout<<a.getX()<<endl;
    // 2.
    const char* str = "whoami";
    cout<<str<<endl;
    return 0;
}