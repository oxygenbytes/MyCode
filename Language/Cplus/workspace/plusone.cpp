#include <vector>
#include <iostream>
using namespace std;

void add(vector<int>& digits, int digit){
    int c = digit;
    for(auto it=digits.rbegin();it !=digits.rend();it++){
        *it += c;
        c = *it / 10;
        *it %= 10;
    }
}

int main(){
    vector<int> v1 = {2,3,1,3,5,9,8};
    add(v1,3);
    for(auto i:v1){
        cout<<i<<" ";
    }
    return 0;
}