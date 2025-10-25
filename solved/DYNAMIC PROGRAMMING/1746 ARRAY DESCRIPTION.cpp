/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
using namespace std;
const int mod = 1e9+7;
//!!!EXPLANATION!!!:
/* 

*/

//Cases

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int N,M;
    cin >> N >> M;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    vector<vector<int>> dp(N,vector<int>(M+2,0));

    for(int i = 1; i <= M; i++){
        dp[0][i]=(v[0] == 0 || v[0]==i);
    }

    for(int i = 1; i < N; i++){
        if(v[i]==0){
            for(int j = 1; j <= M; j++) dp[i][j]=(((dp[i-1][j]+dp[i-1][j-1])%mod)+dp[i-1][j+1])%mod;
        } else{
            int j = v[i];
            dp[i][j]=(((dp[i-1][j]+dp[i-1][j-1])%mod)+dp[i-1][j+1])%mod;
        }
    }

    int ans = 0;
    for(int j = 1; j <= M; j++){
        ans=(ans+dp[N-1][j])%mod;
    }
    cout << ans << '\n';
    return 0;
}
