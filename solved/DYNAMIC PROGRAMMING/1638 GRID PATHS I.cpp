/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
const int mod = 1e9+7;
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

    vector<vector<char>> grid(N,vector<char>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(N,vector<int>(N,0));
    if(grid[0][0]=='*'){
        cout << 0 << '\n';
        return 0;
    }
    dp[0][0]=1;
    int d = 2;
    int dirs[d][2] = {{-1,0},{0,-1}};
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j]=='*') continue;
            for(int k = 0; k < d; k++){
                int nI = i+dirs[k][0];
                int nJ = j+dirs[k][1];
                if(nI >= 0 && nJ >= 0 && nI < N && nJ < N && grid[nI][nJ]!='*'){
                    dp[i][j]=(dp[i][j]+dp[nI][nJ])%mod;
                }
            }
        }
    }
    cout << dp[N-1][N-1] << '\n';
    return 0;
}
