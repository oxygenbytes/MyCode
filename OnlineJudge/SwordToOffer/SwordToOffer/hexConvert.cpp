#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

int main(){
	char str[32];
    int input[32],len;
    int output[100];
    while(~scanf("%s",&str)){
		len=strlen(str);
        // cout<<"len="<<len<<endl;
        // cout<<"*"<<str<<endl;
        for(int i=0;i<len;i++){
            input[i] = str[i] - '0';
        }
        // cout<<"**"<<input[0]<<endl;
        memset(output,0,sizeof(output));
        int sum = 1,d = 0, k = 0;
        while(sum){
            sum = 0;
            for(int i=0;i<len;i++){
                d = input[i] / 2;
                sum += d;
                //对于最后一位，不需要乘以10加给下一位，而是用来判断0,1
                //非最后一位，则负责除2
                //本程序本质上模拟的是使用短除法 + 列式除法 来计算二进制的过程
                if(i == (len - 1)){
                    cout<<"input[i]"<<input[i]<<endl;
                    output[k++] = input[i] % 2;
                }
                else
                    input[i+1] += (input[i]%2)*10;
                input[i] = d;
                for(int i=k-1;i>=0;i--)
                    cout<<output[i];
                cout<<endl;
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