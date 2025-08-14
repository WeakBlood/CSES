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

ll binExp(ll a, ll b, ll mod){
    ll ans = 1;
    while(b > 0){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    ll N;
    cin >> N;
    ll mod = 1e9+7;
    cout << binExp(2LL,N,mod) << '\n';
    return 0;   
}
