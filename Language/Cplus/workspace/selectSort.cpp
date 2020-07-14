//对于数组来说，下标是唯一变量，循环，寻址，取值都是使用下标，
//所以对于数组这种数据结构来说，下标就是最关键的存在

#include <iostream>
using namespace std;
void swap(int &x, int &y){
    int temp = x;
     x = y;
     y = temp;
}

void selectSort(int arr[],int length){
    
    for(int i=0;i <length;i++){
        int k=i;
        for(int j=i;j <length;j++){
            if(arr[j] < arr[k])
                k = j;
        }
        swap(arr[k],arr[i]);
    }
}

int main(){
    int testarr[10] = {12,3,2,4,1,22,12,16,23,10};
    selectSort(testarr, 10);
    for(int i=0;i<10;i++){
        cout<<testarr[i]<<endl;
    }
    return 0;
}