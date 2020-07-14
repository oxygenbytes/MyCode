#include <bits/stdc++.h>
using namespace std;

int main(){
    char str[32];
    int input[32],len;
    int output[100];
    while(~scanf("%s",&str)){
        len = strlen(str);
        for(int i=0;i<len;i++){
            input[i] = str[i] - '0';
        }
        memset(output,0,sizeof(output));
        int sum = 1,d = 0, k = 0;
        while(sum){
            sum = 0;
            for(int i=0;i<len;i++){
                d = input[i] / 2;
                sum += d;
                if(i == (len - 1)){
                    output[k++] = input[i] % 2;
                }
                else
                {
                    input[i+1] += (input[i]%2)*10;
                }
                input[i] = d;
                
            }
        }
        if(k == 0)
            cout<<0;
        else{
            for(int i=k-1;i>=0;i--)
                cout<<output[i];
        }
        cout<<endl;
    }
    return 0;
}