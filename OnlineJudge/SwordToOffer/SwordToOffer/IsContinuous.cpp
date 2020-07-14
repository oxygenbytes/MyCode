#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool IsContinuous( vector<int> numbers ){
        if(numbers.size() < 5)  return false;
        sort(numbers.begin(),numbers.end());
        int NumofZero = 0;
        for(int i = 0;i < numbers.size();i++){
            if(numbers[i] == 0)
                NumofZero ++;
        }
        int gap = 0;
        for(int i = NumofZero;i < numbers.size()-1;i++){
            if(!Diff(numbers[i],numbers[i+1]))
                return false;
            gap += numbers[i+1] - numbers[i] - 1;
        }
        return (gap > NumofZero) ? false : true;
    }
    int Diff(int left,int right){
        return (right - left);
    }
};