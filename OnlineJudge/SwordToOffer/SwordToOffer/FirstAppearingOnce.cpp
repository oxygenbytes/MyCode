#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    void Insert(char ch){
        s += ch; // 字符串中 加法不具有交换律
        um[ch]++;
    }
    char FirstAppearingOnce(){
        for(auto c : s){
            if(um[c] == 1)
                return c;
        }
        return '#';
    }
private:
    unordered_map<char,int> um;
    string s;
};
// class Solution
// {
// public:
//   //Insert one char from stringstream
//     void Insert(char ch)
//     {
//         str += ch;
//         mymap[ch]++;
//     }
//   //return the first appearence once char in current stringstream
//     char FirstAppearingOnce()
//     {   
//         for(auto x:str){
//             if(mymap[x] == 1)
//                 return x;
//         }
//         return '#';
//     }
 
//     private:
//     unordered_map<char,int> mymap;
//     string str;
// };


int main(){
    Solution sol;
    char str[7] = "google";
    for(char c : str){
        sol.Insert(c);
    }
    cout<<sol.FirstAppearingOnce();
    return 0;
}