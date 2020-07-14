#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int L, int M, int R){
    int left_size = M - L;
    int right_size = R - M + 1;
    int left[left_size];
    int right[right_size];
    for (int i = L;i < M; i++){
        left[i-L] = arr[i];
    }
    for (int i = M; i <= R;i++){
        right[i-M] = arr[i];
    }
    // for(int i :left){
    //     printf("%d\n",i);
    // }
    // for(int j : right){
    //     printf("%d\n",j);
    // }
    int a = 0,b = 0,c = L;
    while(a < left_size && b < right_size){
        if(left[a] < right[b]){
            arr[c] = left[a];
            a++;
            c++;
        }else{
            arr[c] = right[b];
            b++;
            c++;
        }
    }
    while(a < left_size){
        arr[c] = left[a];
        a++ ;
        c++;
    }
    while(b < right_size){
        arr[c] = right[b];
        b++;
        c++;
    }
    
}

void mergeSort(int arr[], int L, int R){
    if(L >= R){
        return ;
    }else
    {
        int M = (R - L) / 2 + L;
        mergeSort(arr,L,M);
        mergeSort(arr,M +1,R);
        merge(arr,L,M+1,R);
    }
    

}
int main() {
    int arr[] = {2,8,9,10,4,12,123,23,4,24,5,6,7};
    // merge(arr,0,4,7);
    int length = sizeof(arr) / sizeof(int);
    printf("%d",length);
    cout<<"**"<<endl;
    mergeSort(arr,0, length);

    for(int i = 0;i<length;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}
