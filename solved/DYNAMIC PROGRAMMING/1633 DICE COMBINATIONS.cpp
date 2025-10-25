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
    vector<ll> ways(N+1,0);
    ways[0]=1;

    const int MOD = 1e9+7;
    for(int i = 1; i <= N; i++){
        for(ll k = 1; k <= 6 && k <= i; k++){
            ways[i]=(ways[i]+ways[i-k])%MOD;
        }
    }
    cout << ways[N] << '\n';
    return 0;
}
