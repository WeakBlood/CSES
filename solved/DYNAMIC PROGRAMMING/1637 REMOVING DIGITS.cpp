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

vector<int> decompose(int x){
    vector<int> digs;
    while(x > 0){
        digs.push_back(x%10);
        x/=10;
    }
    return digs;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int N;
    cin >> N;
    vector<int> dp(N+1,inf);
    dp[0]=0;
    for(int i = 1; i <= N; i++){
        auto digs = decompose(i);
        for(int d:digs){
            if(i-d >= 0){
                dp[i]=min(dp[i],dp[i-d]+1);
            }
        }
    }
    cout << dp[N] << '\n';
    return 0;
}
