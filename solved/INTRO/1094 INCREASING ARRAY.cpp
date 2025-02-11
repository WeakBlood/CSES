/* 
Sender:	WeakBlood
Submission time:	2025-02-11 18:20:59 +0200
Language:	C++ (C++17)
Status:	READY
Result:	ACCEPTED
*/
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
    int T = 1;
    while(T--){
        int N;
        cin >> N;
        ll ans = 0;
        int prev;
        cin >> prev;
        for(int i = 1; i < N; i++){
            int a; 
            cin >> a;
            if(a < prev){
                ans += (prev-a);
                a  = a + (prev-a);
            }
            prev = a;
        }
        cout << ans << '\n';
    }
    return 0;
}
