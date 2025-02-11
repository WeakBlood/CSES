/* 
Sender:	WeakBlood
Submission time:	2025-02-11 19:44:09 +0200
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
Let's look at the problem statement by another angle, let's ask ourselves: "How many numbers can we make with N bits?".
Now, we all know that with N bits we can make 2ᴺ different numbers ( 0 included ), but there is a problem here,
2ᴺ with N = 10⁶ could be pretty big, so the problem asks to do it MODULO 10⁹+7 to make it feasible.
*/

/*For the solution we will be using a classic but really powerful technique called Binary Exponentiaion 
that allows us to calculate any pow operation in only O(log₂(N)) time while also specifying a mod.
// More about this technique on https://cp-algorithms.com/algebra/binary-exp.html

*/


ll fastExp(ll a, ll exp, ll mod){
    ll res = 1;
    while(exp > 0){
        if(exp&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        exp>>=1;
    }
    return res;
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
        ll MOD = 1e9+7;
        cout << fastExp(2,N,MOD) << '\n';
    }
    return 0;
}
