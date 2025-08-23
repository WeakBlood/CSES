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
    multiset<int> s;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        s.insert(a);
    }

    int ans = 0;
    while(!s.empty()){
        int a = *s.begin();
        s.erase(s.begin());
        ans++;
        //cout << a << ' ';
        if(s.empty()) continue;

        // actual logic 
        // we find the closest to X-a 
        auto it = s.upper_bound(X-a);
        if(it!=s.begin()){
            it--;
            //cout << *it;
            s.erase(it);
            // this way we removed to and it is perfect :) 
        }
        //cout << '\n';
    }

    cout << ans << '\n';
    return 0;
}
