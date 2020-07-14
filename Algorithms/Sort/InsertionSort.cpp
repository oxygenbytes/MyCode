#include <bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> & arr){
    int temp ;
    for(int i = 1;i < arr.size();i++){
        temp = arr[i];
        int j;
        for(j = i - 1;j >= 0 && arr[j] > temp;j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
        
    }
}

int main(){
    vector<int> v = {5,12,4,3,5,2,1,3,6,12,18,-2,9};
    InsertionSort(v);
    for(int t : v)
      cout<<t<<" ";
      cout<<endl;
    return 0;   
}