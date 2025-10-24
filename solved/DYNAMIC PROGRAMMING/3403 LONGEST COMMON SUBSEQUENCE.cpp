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
    vector<int> a(N),b(M);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < M; i++){
        cin >> b[i];
    }

    vector<vector<int>> dp(N+1,vector<int>(M+1,0));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout << dp[N][M] << '\n';
    vector<int> ans;
    int i = N, j = M;
    while(i > 0 && j > 0){
        if(a[i-1]==b[j-1]){
            ans.push_back(a[i-1]);
            j--; i--;
        } else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    reverse(ans.begin(),ans.end());
    for(int c:ans){
        cout << c << ' ';
    }
    return 0;
}
