/* ccf-csp
 * 201903-1 小中大
 * @author:cogitates
 */
#include <bits/stdc++.h>
using namespace std;

int num[100000] = {0};
int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n;i++){
        cin>>num[i];
    }
    int biggest = num[0];
    int smallest = num[n-1];
    if(biggest < smallest) swap(biggest,smallest);
    double mid ;
    if(n%2 == 1){
        // 注意 printf和cout不要混用
        // 另外不要对浮点数使用%d输出
        printf("%d %d %d",biggest,num[(n-1)/2],smallest);
        // cout<<biggest<<" "<<mid<<" "<<smallest;
    }
    else{
        mid = (double)(num[n/2 -1] + num[n/2]) / 2;
        if((num[n/2-1] ^ num[n/2]) & 1) printf("%d %.1f %d",biggest,mid,smallest);
        else  printf("%d %d %d",biggest,(num[n/2-1]+num[n/2])>>1,smallest);
        
        
    }
    return 0;
}

