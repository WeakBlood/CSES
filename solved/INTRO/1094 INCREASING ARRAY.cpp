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
    int T;
    T = 1;
    while(T--){
        int N;
        cin >> N;
        vector<ll> v(N);
        ll ans = 0;
        cin >> v[0];
        for(int i = 1; i < N; i++){
            cin >> v[i];
            if(v[i] < v[i-1]){
                ans+=(v[i-1]-v[i]);
                v[i]=v[i-1];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
