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
    int T = 1;
    while(T--){
        ll N;
        cin >> N;
        ll sum = (N*(N+1))/2;

        if(N < 3 || sum%2 != 0){
            cout << "NO" << '\n';
            continue;
        }
        vector<int> a;
        vector<int> b;
        sum/=2;
        for(ll i = N; i >= 1; i--){
            if(sum-i>=0){
                a.push_back(i);
                sum-=i;
            } else b.push_back(i);
        }
        cout << "YES" << '\n';
        cout << a.size() << '\n';
        for(int n:a) cout << n << ' ';
        cout << '\n';
        cout << b.size() << '\n';
        for(int n:b) cout << n << ' ';
        cout << '\n';
    }
    return 0;
}
