#include <bits/stdc++.h>
using namespace std;

struct bignumber{  // 大数结构体，使用字符数组保存bignumber
    int d[100];
    int len;
    bignumber(){ // 初始化
        memset(d,0,sizeof(d));
        len = 0;
    }
};
int r = 0;

bignumber add(bignumber a, bignumber b){
    bignumber c;
    int carry = 0;
    
    for(int i = 0;i < a.len || i < b.len;i++){
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0)
        c.d[c.len++] = carry;
    return c;
}

bignumber  change(char s[]){
    bignumber a;
    a.len = strlen(s);
    for(int i = 0 ;i <a.len;i++){
        a.d[i] = s[a.len-i-1] - '0';
    }
    return a;
}

void print_bignumber(bignumber a){
    for(int i = a.len-1;i>=0;i--){
        cout<<a.d[i];
    }
    cout<<endl;
}

bignumber divide(bignumber a,int b,int &r){
    bignumber c;
    c.len = a.len;
    for(int i = a.len - 1; i >= 0;i--){
        r = r * 10 + a.d[i];
        if(r < b) c.d[i] = 0;
        else{
            c.d[i] = r / b;
            r = r % b;
        }
    }
    while(c.len - 1 >= 1 && c.d[c.len-1] == 0){
        c.len--;
    }
    return c;
}

void sum_bignumber(char str1[],int b){
    bignumber a = change(str1);
    print_bignumber(a);
    print_bignumber(divide(a,b,r));
}

int main(){
    char str1[1000];
    int b;
    cout<<"str1:";
    cin>>str1;
    cout<<"b:";
    cin>>b;
    sum_bignumber(str1,b);
    return 0;
}