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

    vector<int> price(N),pages(N);
    for(int i  = 0; i < N; i++){
        cin >> price[i];
    }
    for(int i = 0; i < N; i++){
        cin >> pages[i];
    }

    vector<int> dp(X+1,0);
    for(int i = 0; i < N; i++){
        for(int w = X; w >= price[i]; w--){
                dp[w]=max(dp[w],dp[w-price[i]]+pages[i]);
        }
    }
    cout << dp[X] << '\n';
    return 0;
}
