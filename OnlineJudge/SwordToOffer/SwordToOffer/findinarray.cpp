#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 bool binarySearch(int target, vector<int> array){
     int first = 0;
     int last = array.size() - 1;
     int middle = 0;
     if (target == array[first] || target == array[last])
         return true;
     while(first < last){
         middle = first + (last - first) /2;
         if (target == array[middle])
             return true;
         else if (target < array[middle])
             last = middle;
         else 
             first = middle + 1;
     }
     return false;
 }
bool Find(int target, vector<vector<int> > array) {
    int m = array.size();
    int n = array[0].size();
    //bool judge = false;
    cout<<"m"<<m<<"n"<<n<<endl;
    for(int i=0;i<m;i++){
        if (BinarySearch(array[i].begin(),array[i].size(),target))
            return true;
    }
    return false;
}

int main(){
    vector<vector<int>> array;
    array = {
        {1,2,4,6,7},
        {2,3,5,7,8},
        {3,5,7,10,12}
    };
    cout<<Find(3,array);
    cout<<" "<<"over"<<endl;
    return 0;
}
