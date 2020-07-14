#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v2;
    for(int i=0;i<30;i++){
        v2.push_back(i*2);
    }
    for(int i=0;i<20;i++){
        v2.pop_back();
    }
    v2.insert(v2.begin() + 10, -12);
    for(int i : v2)
        cout<<i<<" ";
    cout<<v2.size();
    return 0;
}