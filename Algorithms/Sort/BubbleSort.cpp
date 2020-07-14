/*name:bubble sort
  author:cogitates
 */
#include <bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> & arr){
    for(int i=arr.size() -1;i > 0;i--){ //利用双指针的思路来实现冒泡排序 i是右指针，j是左指针
        for(int j = 0;j < i; j++){
            if(arr[j] > arr[j + 1]) //数组是线性序列的性质，下个元素的键i+1,下下个元素的键i+2
                swap(arr[j], arr[j+1]);
        }
    }
}

int main(){
    vector<int> v = {5,12,4,3,5,2,1,3,6,12,18,-2,9};
    BubbleSort(v);
    for(int t : v)
      cout<<t<<" ";
      cout<<endl;
    return 0;   
}