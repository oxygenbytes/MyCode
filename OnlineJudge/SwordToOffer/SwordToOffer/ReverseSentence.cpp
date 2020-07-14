#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string ReverseSentence(string str){
        ReverseWord(str,0,str.size()-1);
        int s = 0, e = 0;
        int i = 0;
        while(i < str.size()){
            while(i < str.size() && str[i] == ' ')
                i++;
            e = s = i;
            while(i < str.size() && str[i] != ' '){
                i++;
                e++;
            }
            ReverseWord(str,s,e-1);
        }
        return str;
    }
    void ReverseWord(string &str,int s,int e){
        while(s < e)
            swap(str[s++],str[e--]);
    }
};

int main(){
    string str = "I am a student.";
    Solution s;
    cout<<s.ReverseSentence(str);
    return 0;
}