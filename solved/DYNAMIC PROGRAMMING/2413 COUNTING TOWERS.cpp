/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
using namespace std;

//!!!EXPLANATION!!!:
/* 

*/

//Cases
const int mod = 1e9+7;
const int MAXN = 1e6+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    vector<vector<ll>> dp(MAXN+1,vector<ll>(2,0));
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i = 1; i <= MAXN; i++){
        dp[i][0]=(2LL*dp[i-1][0]+dp[i-1][1])%mod;
        dp[i][1]=(4LL*dp[i-1][1]+dp[i-1][0])%mod;
    }
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        cout << (dp[N-1][0]+dp[N-1][1])%mod << '\n';
    }
    return 0;
}
