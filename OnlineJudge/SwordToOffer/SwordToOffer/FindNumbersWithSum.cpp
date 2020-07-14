#include <bits/stdc++.h>
using namespace std;

class  Solution{
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum){
        vector<int> result;
        int length = array.size();
        int start = 0;
        int end = length-1;
        while(start < end){
            if(array[start] + array[end] == sum){
                result.push_back(array[start]);
                result.push_back(array[end]);
                break;
            }
            else if(array[start] + array[end] < sum)
                start++;
            else
                end--;
        }
        return result;
    }
};