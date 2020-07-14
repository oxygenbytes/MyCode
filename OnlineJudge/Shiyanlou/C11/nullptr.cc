// nullptr

#include <bits/stdc++.h>
void foo(char *);
void foo(int);
int main() {

    if(NULL == (void *)0) std::cout << "NULL == 0" << std::endl;
    else std::cout << "NULL != 0" << std::endl;

    foo(0);
    // foo(NULL); // 编译无法通过
    foo(nullptr); // C++ 11 引入了 nullptr 关键字，专门用来区分空指针、0。nullptr 的类型为 nullptr_t，能够隐式的转换为任何指针或成员指针的类型，也能和他们进行相等或者不等的比较。

    return 0;
}
void foo(char *ch) {
    std::cout << "call foo(char*)" << std::endl;
}
void foo(int i) {
    std::cout << "call foo(int)" << std::endl;
}