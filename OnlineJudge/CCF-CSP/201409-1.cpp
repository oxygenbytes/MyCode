#include <bits/stdc++.h>
using namespace std;
void QuickSort(vector<int>& arr,int left,int right);
int main(){
    vector<int> v;
    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        v.push_back(x);
    }
    // sort(v.begin(),v.end());
    QuickSort(v,0,v.size()-1);
    int i = 0,cnt=0;
    while(i <v.size()-1){
        while(i < v.size()-1 && v[i+1] - v[i] == 1){
            ++i;
            ++cnt;
        }
        ++i;
    }
    cout<<cnt;
    return 0;
}

void QuickSort(vector<int> &arr,int left,int right){
    if(left < right){
        int i, j, x;
        i = left;
        j = right;
        x = arr[i];
        while(i < j){
            while(i < j && arr[j] > x)
                j--;
            if(i < j)
                arr[i++] = arr[j];
            while(i < j && arr[i] < x)
                i++;
            if(i < j)
                arr[j--] = arr[i];
        }
        arr[i] = x;
        QuickSort(arr,left,i-1);
        QuickSort(arr,i+1,right);
    }
}