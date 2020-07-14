#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isNumeric(char* string){
        if(string == nullptr){
            return false;
        }
        if(*string=='+'||*string=='-'){
            ++string;
        }
        if(*string=='\0'){
            return false;
        }
        while(*string!='\0' && *string<='9' && *string>='0')
            ++string;
        bool flag = true;
        if(*string != '\0'){
            if(*string == '.'){
                ++string;
                while(*string!='\0' && *string<='9' && *string >='0')
                    ++string;
                if(*string == 'e' || *string == 'E'){
                    flag=isExponent(&string);
                }
            }
            else if(*string == 'e' || *string == 'E'){
                   flag=isExponent(&string);
            }
            else 
                   flag = false;
            
        }
        return flag&&*string=='\0';
    }
    bool isExponent(char** string){ // 判断过程相同，但是判断结束，string会改变，相当于&引用
        if(**string != 'E' && **string != 'e')
            return false;
        ++(*string);
        if(**string=='+' || **string=='-')
            ++(*string);
        if(**string=='\0')
            return false;
        while(**string!='\0'&&**string<='9' && **string>='0'){
            ++(*string);
        }
        if(**string=='\0'){
            return true;
        }
        else 
            return false;
    }
    bool isEXponent(char* string){ // 判断过程相同，但是判断结束，string不会改变，本质上是值传递
        if(*string != 'E' && *string != 'e'){
            return false;
        }
        ++string;
        if(*string == '+' || *string =='-'){
            ++string;
        }
        if(*string=='\0'){
            return false;
        }
        while(*string != '\0' && *string <= '9' && *string >='0'){
            ++string;
        }
        if(*string == '\0')
            return true;
        else return false;
    }
};

int main(){
    char str[10] = "100";
    Solution s;
    cout<<s.isNumeric(str)<<endl;
    return 0;
}