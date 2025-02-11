/* 
Sender:	WeakBlood
Submission time:	2025-02-11 19:02:52 +0200
Language:	C++ (C++17)
Status:	READY
Result:	ACCEPTED
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
using namespace std;

//!!!EXPLANATION!!!:
/* 
For any given N the problem asks us to find two sets that have the same sum using all elements from 1 to N.
This means that if the Σ₁ᴺ is even, then THERE IS at least one way for it to be obtained from 2 groups otherwise there is no way
to achieve it, at least not with integer values.

Once we know that Σ₁ᴺ is even, we just need to split this value by 2 and try to reach it with every integer
from N to 1 that is less than it and each time we reduce the target value ( target = (Σ₁ᴺ)/2 ) if the target is less than 
the integer then we should add it to the other set.

Talking about complexity, this is just O(N)

*/

//Cases

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    #endif
    int T = 1;
    while(T--){
        ll N;
        cin >> N;
        ll sum = (N*(N+1))/2;
        if(sum&1){
            cout << "NO" << '\n';
        } else{
            ll target = sum/2;
            vector<ll> firstSet,secondSet;
            for(ll i = N; i >= 1; i--){
                if(target >= i){
                    firstSet.push_back(i);
                    target-=i;
                } else{
                    secondSet.push_back(i);
                }
            }
            cout << "YES" << '\n';
            cout << firstSet.size() << '\n';
            for(int u:firstSet) cout << u << ' ';
            cout << '\n';

            cout << secondSet.size() << '\n';
            for(int u:secondSet) cout << u << ' ';
            cout << '\n';
        }
    }
    return 0;
}
