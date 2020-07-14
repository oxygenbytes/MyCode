#include <iostream>
using namespace std;
typedef int (*funcptr)(int, int);
int add(int a,int b){
    return a+b;
}
int test(funcptr ptr,int x, int y){
    cout<<"this is a test";
    return ptr(x, y);
}
int main(){
    cout<<test(add,2,3)<<endl;
    cout<<test(&add,3,4)<<endl;
    cout<<&main;
    return 0;
}