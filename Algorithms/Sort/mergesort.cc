#include <bits/stdc++.h>
using namespace std;

int aux[20];

void merge(vector<int>& arr, int left, int mid, int right){
    int i = left;
    int j = mid+1;
    
    for(int i = left;i <= right;i++){
        aux[i] = arr[i];
    }

    for(int k = left;k <= right;k++){
        if(i > mid) arr[k] = aux[j++];
        else if(j > right) arr[k] = aux[i++];
        else if(aux[i] > aux[j]) arr[k] = aux[j++];
        else arr[k] = aux[i++];
    }

}

void mergesort(vector<int>& arr, int left, int right){
    if(left < right){
        int mid = (right - left) / 2 + left;
        mergesort(arr, left, mid);
        mergesort(arr,mid+1, right);
        merge(arr,left,mid,right);
    }
}



int main(){
    vector<int> s ={1,32,23,12, 4, 4};
    mergesort(s,0,s.size()-1);
    for(auto x : s){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}