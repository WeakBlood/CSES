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
    int N,M;
    cin >> N >> M;
    vector<vector<int>> dp(N+1,vector<int>(M+1,inf));
    for(int i = 1; i <= N && i <= M; i++){
        dp[i][i]=0;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(i == j) continue;
            for(int k = 1; k < j; k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
            } 
            for(int k = 1; k < i; k++){
                dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
            }
        }
    }
    cout << dp[N][M] << '\n';
    return 0;
}
