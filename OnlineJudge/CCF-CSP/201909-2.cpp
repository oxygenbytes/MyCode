// INFO BEGIN
//
// User = 201910013552(张学庆) 
// Group = C/C++ 
// Problem = 小明种苹果（续） 
// Language = CPP11 
// SubmitTime = 2019-09-15 16:16:56 
//
// INFO END

#include <bits/stdc++.h>
using namespace std;

int apple[1024] = {0};
int visit[1024] = {0};

void help(int i ,int temp){
    if(temp > 0){
        if(apple[i] > temp){
            visit[i] = 1;
        }
        apple[i] = temp;
    }
    else{
        apple[i] += temp;
   }
}

int find_three_drop(int n){
    int result = 0;
    for(int i = 1;i <=n;i++){
        if(visit[i] && visit[i+1] && visit[i+2])  result++;
    }
    return result;
}
int main(){
    int n;
    scanf("%d",&n);
    int number;
    int temp;
    for(int i = 1;i <= n;i++){
        scanf("%d",&number);
        for(int j = 1;j <= number;j++){
            scanf("%d",&temp);
            if(j == 1) apple[i] = temp;
            else help(i,temp);
         //   printf("j loop\n");
        }
       // printf("i loop\n");
    }
    // printf("test\n");
    long long int total = 0;
    int drop = 0;
    for(int i = 1;i <= n;i++){
        if(visit[i]) drop++;
        total += apple[i];
    }
    visit[n+1] = visit[1];
    visit[n+2] = visit[2];
    int drop_three = find_three_drop(n);
    cout<<total<<" "<<drop<<" "<<drop_three<<endl;
    return 0;
}
