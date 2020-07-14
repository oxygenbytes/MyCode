/* ccf-csp
 * 201312-3
 * author:cogitates
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int h[N+1];

int main(){
    int n;
    cin>>n;

    for(int i = 0;i < n; i++){
        cin>>h[i];
    }
    h[n] = 0;
    
    int area,ans= -1;
    // 使用单调栈保存左侧第一个比当前节点小的节点，将时间复杂度降到O(n)
    stack<int> s;
    for(int i = 0;i <= n;i++){
        if(s.empty() || h[s.top()] < h[i]){
            s.push(i);
        }
        else{
            int temp = s.top();
            s.pop();
            area = h[temp] * (s.empty()?i:i-s.top()-1); // 找比你最小的数，而最小的数不参与计算以你为高的矩形面积
            if(ans < area)
                ans = area;
            i--;
        }
    }
    cout<<ans;
    return 0;
}