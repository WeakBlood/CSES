/* WeakBlood <3 */
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    ll N;
    cin >> N;
    cout << N << ' ';

    while(N > 1){
        if(N&1)N = N*3 + 1;
        else N/=2;
        cout << N << ' ';
    }
    return 0;
}
