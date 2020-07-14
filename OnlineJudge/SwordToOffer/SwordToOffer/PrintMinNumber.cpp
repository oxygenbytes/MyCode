#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    static bool compare(int a,int b){
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        return s1 < s2;
    }
    string PrintMinNumber(vector<int> numbers){
        string res;
        sort(numbers.begin(),numbers.end(),compare);
        for(int i = 0;i < numbers.size();i++){
            res += to_string(numbers[i]);
        }
        return res;
    }
};

int main(){
    vector<int> v = {12,2345,1,34};
    Solution s;
    cout<<s.PrintMinNumber(v);
    return 0;
}