/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
using namespace std;

//!!!EXPLANATION!!!:
/* 
In this problem we assume immediatly that is possible to solve it by sliding window for a O(N) base complexity because it is asking us for SUBARRAYS
so CONTIGUOS SEGMENTS OF ARRAY.
Then, for keeping track of the elemnts we can use a set, for O(log n) insertion and deletions,
whenever we add a new a value, we keep deleting all the previous ones from the oldest one until we have all elements distincts, this is guaranteed by the fact
that we do this for adding any value so the values in the set will always be unique. In total we get (NlogN) complexity or more precisely (2*NlogN)
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
    vector<int> v(N);
    ll ans = N;
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    ll l = 0;
    ll r = 0;
    set<int> s;
    while(r < N){
        while(!s.empty() && s.count(v[r]) && l < r){
            s.erase(v[l++]);
        }
        s.insert(v[r]);
        //cout << l << ' ' << r << '\n';
        ans+=(r-l); // you did another array 
        r++;
    }

    cout << ans << '\n';
    return 0;
}
