/* ccf-csp
 * 201903-2 ISBN号码
 * @author:cogitates
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    char ISBN[13];
    int i = 0;
    // So scanf("%[^\n]", s); will read all characters until you reach \n (or EOF) and put them in s. 
    // It is a common idiom to read a whole line in C.
    scanf("%[^\n]",&ISBN); //c语言如何读入一整行字符串
        // int sum = atoi(ISBN[0])*1 + atoi(ISBN[2])*2 + atoi(ISBN[3])*3 + atoi(ISBN[4])*4 
        // + atoi(ISBN[5])*5 + atoi(ISBN[6])*6
    int weight = 1;
    int total = 0;
    for(int i = 0 ;i < 13 - 1;i++){
        if(ISBN[i] >= '0' && ISBN[i] <= '9') 
            total += (weight++)*(ISBN[i] - '0');
    }
    if(total % 11 == (ISBN[12] - '0')) 
        cout<<"Right";
    else if(total % 11 == 10 && (ISBN[12] == 'X'))
        cout<<"Right";
    else{
        for(int i=0;i < 13 -1;i++){
            cout<<ISBN[i];
        }
        if(total % 11 == 10) cout<<'X';
            else cout<<total % 11;
    }
        
    return 0;
}