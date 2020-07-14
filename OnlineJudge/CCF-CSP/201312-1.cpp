/* ccf-csp
 * 201312-1 出现次数最多的数
 * @author:cogitates
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v2(10001,0);
    v2.push_back(0);
    int n ;
    cin>>n;
    int temp;
    for(int i = 1;i <= n; i++){
        cin>>temp;
        v2[temp] ++; 
    }
    int max = 0;
    int real;
    for(int i = 1;i <= 10000;i++){
        if(v2[i] > v2[max])
            max = i;
    }
    cout<<max;
    return 0;

}