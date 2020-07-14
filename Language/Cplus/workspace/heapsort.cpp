#include <iostream>
using namespace std;

template<typename T>
void swap(T* i,T* j){
    T temp = i;
    i = j;
    j = temp;
}
//对于完全二叉树来说，若其中的某个节点的顺序值是i
//那么这个节点的基本情况就是
// parent = (i-1)/2;
//  left = 2 * i + 1;
//  right = 2 * i + 2;
template<typename T> //函数模板每个函数前面都要声明
void heapify(T arr[], int num,int i){ //num是数组的长度，对第i个节点进行heapify的操作
        if (i >= num){
            return ;
        }
        int c1 = 2 * i + 1;
        int c2 = 2 * i + 2;
        int max = i;
        if(arr[max] < arr[c1] && c1 < num){
            max = c1;
        }
        if(arr[max] < arr[c2] && c2 <num ){
            max = c2;
        }
        if(max != i){
            swap(arr[i], arr[max]);
            heapify(arr,num,max);
        }
    }

template<typename T>
void build_heap(T arr[], int n){
    int last_node = (n-1)/2;
    for(int i=last_node;i >= 0;i--){
        heapify(arr, n, i);
    }
}
template<typename T>
void heap_sort(T arr, int n){
    build_heap(arr,n);
    for(int i=n-1;i >=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,i,0);
    }
}
int main(){
    double x[]={2, 5, 3, 1, 10, 4};
    // heapify(x, 6, 0);
    // build_heap(x,6);
    heap_sort(x,6);
    for(int i=0;i<6;i++){
        cout<<x[i]<<" ";
    }
    return 0;
}