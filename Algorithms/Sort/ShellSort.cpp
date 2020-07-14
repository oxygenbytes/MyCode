#include <bits/stdc++.h>
using namespace std;

void ShellSort(vector<int> &arr){
    int length = arr.size();
    int h = 1;
    while (h < length / 3) h = h * 3 + 1; // æ­¤å¤„ä½¿ç”¨while
    while(h >= 1){
        for(int i= h;i < length; i++){
            for(int j = i;j >= h && arr[j] < arr[j-h];j -= h){
                swap(arr[j],arr[j-h]);
            }
        }
        h = h / 3;
    }
}

int main(){
    vector<int> v = {5,12,4,3,5,2,1,3,6,12,18,-2,9};
    ShellSort(v);
    for(int t : v)
      cout<<t<<" ";
      cout<<endl;
    return 0;   
}