//如何理解堆排序？
// 首先理解heapify,
// 其本质是给定一个节点,现在假定这个节点的left树和right树都是满足
// 而heapify的目的就是让这个节点和其左右子树整体构成一个heap,
//如果该节点被下放到左分支,那么右分支仍是heap,且与根节点也满足heap性质
// 而左分支不满足,那么我们就处理左分支,递归的执行下去,就能将整体都处理成heap

#include <iostream>
using namespace std;

template<typename T>
void swap(T* i, T* j){
    T temp = i;
    i = j;
    j = temp;
}

template<typename T>
void heapify(T arr[], int num,int i){
    if(i >= num){
        return ;
    }

    int c1 = 2*i +1;
    int c2 = 2*i + 2;
    int max = i;
    if(arr[max] < arr[c1] && c1 < num){
        max = c1;
    }
    if(arr[max] < arr[c2] && c2 < num){
        max = c2;
    }
    if(max != i){
        swap(arr[i], arr[max]);
        heapify(arr, num, max);
    }
}

template<typename T>
void build_heap(T arr, int n){
    int last_node = (n-2)/2;
    for(int i = last_node;i >= 0;i--){
        heapify(arr,n,i);
    }
}

template<typename T>
void heap_sort(T arr, int n){
    build_heap(arr, n);
    for(int i=n-1;i >= 0;i--){
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}
 
int main(){
    int test_heap[] = {4,5,6,1,23,56,14};
    heap_sort(test_heap,7);
    for(int i=0;i<7;i++){
        cout<<test_heap[i]<<" ";
    }
    return 0;
}
