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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int N;
    cin >> N;
    int tot = 0;
    vector<int> coins(N);
    for(int i = 0; i < N; i++){
        cin >> coins[i];
        tot+=coins[i];
    }

    vector<bool> dp(tot+1,0);

    dp[0]=true;
    int ans = 0;
    for(int coin:coins){
        for(int i = tot; i >= coin; i--){
            if(dp[i]) ans--;
            dp[i]=max(dp[i],dp[i-coin]);
            if(dp[i]) ans++;
        }
    }

    cout << ans << '\n';
    for(int i = 1; i <= tot; i++){
        if(dp[i]) cout << i << ' ';
    }

    return 0;
}
