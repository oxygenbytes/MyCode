#include <vector>
#include <iostream>
using namespace std;
int fibonacci(int n){
    cout<<"e";
    if(n == 1 || n ==2) return 1;
    else return fibonacci(n-1) + fibonacci(n-2);
}
int superfib(int n){
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    for(int i=3;i<=n;i++){
        v[i] = v[i-1] + v[i-2] ;
        cout<<"e";
    }
    cout<<endl;
    return v[n];
    
}
int main(){
    cout<<superfib(12);
    cout<<fibonacci(12);
    return 0;
}