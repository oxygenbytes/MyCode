#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int left,int right){
    int dad = left;
    int son = dad * 2 + 1;

    while(son <= right){
        if(son + 1 <= right && arr[son+1] > arr[son]){
            son = son + 1;
        }
        if(arr[dad] > arr[son]){
            return ;
        }else{
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heapsort(vector<int>& arr, int left, int right){
    for(int i = right / 2; i >= 0;i--){
        heapify(arr, i, right);
    }

    for(int i = right;i >= 0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,0,i-1);
    }
}

int main(){
    vector<int> s ={1,32,23,12, 4, 4};
    heapsort(s,0,s.size()-1);
    for(auto x : s){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}