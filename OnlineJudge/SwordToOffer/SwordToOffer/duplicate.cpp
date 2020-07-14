#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool duplicate(int numbers[],int length ,int* duplication){
        if(length == 0)
            return false;
        for(int i = 0;i < length;i++){
            while(numbers[i]!=i){
                if(numbers[i]==numbers[numbers[i]]){
                    *duplication = numbers[i];
                    return true;
                }
                swap(numbers[i],numbers[numbers[i]]);
            }
        }
        return false;
    }
};

int main(){
    int arr[10] = {1,2,3,4,2,45,3,2,78,3};
    Solution s;
    int du;
    cout<<s.duplicate(arr,10,&du)<<endl;
    cout<<du<<endl;
    return 0;
}