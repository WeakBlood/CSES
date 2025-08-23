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
        int N,M,K;
        cin >> N >> M >> K;
        int ans = 0;
        vector<int> v(N);
        for(int i = 0; i < N; i++){
            cin >> v[i];
        }

        multiset<int> s;
        for(int i = 0; i < M; i++){
            int a;
            cin >> a;
            s.insert(a);
        }

        sort(v.begin(),v.end());
        for(int i = 0; i < N; i++){
            auto it = s.lower_bound(v[i]-K);
            if(it != s.end()){
                int x = *it;
                if(x >= v[i]-K && x <= v[i]+K){
                    ans++;
                    s.erase(it);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
