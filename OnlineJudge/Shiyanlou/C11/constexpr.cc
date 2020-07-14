// constexpr
#include <bits/stdc++.h>
using namespace std;

// c14 only
constexpr int fibonacci(const int n) {
    if(n == 1) return 1;
    if(n == 2) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){

    cout<<fibonacci(10)<<endl;
    return 0;
}