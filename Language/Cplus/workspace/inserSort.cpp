//当你的下标在j的时候，你不要死脑筋的认为，你当前只能索引arr[j]
//记住，当你的下标在j的时候，你可以索引arr[i+1], arr[i+2],arr[i-1],arr[i-2]……

#include <iostream>
using namespace std;

void insertSort(int arr[],int length){
    int temp =0;
    for(int i=1;i<length;i++){
         temp = arr[i];
        for(int j=i-1;;j--){
            if(temp > arr[j] || j ==-1){
                arr[j+1] = temp;
                break;
            }
                
        arr[j+1] = arr[j];
        }
    }
}

int main(){
    int testarr[10] = {12,3,2,4,1,22,12,16,23,10};
    insertSort(testarr, 10);
    for(int i=0;i<10;i++){
        cout<<testarr[i]<<endl;
    }
    return 0;
}