#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> v1;
    for(int i=0;i<100;i++){
        if(i%3 ==0)
            v1.push_back(i);
    }
    vector<int>::iterator it;
    for(vector<int>::iterator it=v1.begin(); it != v1.end();it++){
        *it += 2;
        cout<<*it<<endl;
        
    }
    return 0;
}
