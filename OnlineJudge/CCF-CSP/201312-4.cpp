/* ccf-csp
 * author:cogitates
 * 201312-4
 */
#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
const ll mod = 1000000007;
ll status[1024][6] ;
ll n;
int main(){
    scanf("%lld",&n);
    // 如果a≡b(mod m)，x≡y(mod m)，则a+x≡b+y(mod m)。
    // 如果a≡b(mod m)，x≡y(mod m)，则ax≡by(mod m)。
    // 如果ac≡bc(mod m)，且c和m互质，则a≡b(mod m) （就是说同余式两边可以同时除以一个和模数互质的数）。
    for(int i = 1;i <= n;++i){
        // status[i][0] = 1;
        // status[i][1] = (status[i-1][0] + status[i-1][1]*2)%mod;
        // status[i][2] = (status[i-1][0] + status[i-1][2])%mod;
        // status[i][3] = (status[i-1][1] + status[i-1][3]*2)%mod;
        // status[i][4] = (status[i-1][1] + status[i-1][2] + status[i-1][4]*2)%mod;
        // status[i][5] = (status[i-2][3] + status[i-1][4] + status[i-1][5]*2)%mod;
        // 最后一行中 status[i-2]错误 ，应为[i-1]
        status[i][0] = 1;
		status[i][1] = (status[i - 1][1] * 2 + status[i - 1][0]) % mod;
		status[i][2] = (status[i - 1][2] + status[i - 1][0]) % mod;
		status[i][3] = (status[i - 1][3] * 2 + status[i - 1][1]) % mod;
        status[i][4] = (status[i - 1][4] * 2 + status[i - 1][2] + status[i - 1][1]) % mod;
		status[i][5] = (status[i - 1][5] * 2 + status[i - 1][4] + status[i - 1][3]) % mod;
    }
    printf("%lld\n",status[n][5]);
    return 0;
}