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
    int N,X;
    cin >> N >> X;
    vector<int> coins(N);
    for(int i = 0; i < N; i++){
        cin >> coins[i];
    }

    vector<int> dp(X+1,inf);
    dp[0]=0;

    for(int i = 1; i <= X; i++){
        for(int coin:coins){
            if(i-coin >= 0){
                dp[i]=min(dp[i],dp[i-coin]+1);
            }
        }
    }
    cout << (dp[X]==inf?-1:dp[X]) << '\n';
    return 0;
}
