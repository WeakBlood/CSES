/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
const ll inf = 1e18;
using namespace std;

//!!!EXPLANATION!!!:
/* 

*/

//Cases
ll dp(ll lSum, ll rSum, int i, const vector<ll> &v){
    if(size_t(i+1) ==  v.size()) return min(abs((lSum+v[i])-rSum),abs((rSum+v[i])-lSum));
    return min(dp(lSum+v[i],rSum,i+1,v),dp(lSum,rSum+v[i],i+1,v));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int T;
    T = 1;
    while(T--){
        ll N;
        cin >> N;
        vector<ll> v(N);
        for(int i = 0; i < N; i++){
            cin >> v[i];
        }
        cout << dp(0LL,0LL,0,v) << '\n';
    }
    return 0;
}
