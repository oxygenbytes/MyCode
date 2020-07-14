#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int left, int right){
    int pivot = arr[left];
    int i = left;
    int j = right+1;
    while(true){
        while(arr[++i] < pivot){
            if(i == right) break;
        }
        while(arr[--j] > pivot){
            if(j == left) break;
        }
        if(i >= j) break;
        swap(arr[i],arr[j]);
    }
    swap(arr[left],arr[j]);
    return j;
}


void quicksort(vector<int>& arr,int left, int right){
    if(left < right){
        int j = partition(arr,left,right);
        quicksort(arr, left, j-1);
        quicksort(arr, j+1, right);
    }
}


int main(){
    vector<int> s ={1,32,23,12, 4, 4};
    quicksort(s,0,s.size()-1);
    for(auto x : s){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}