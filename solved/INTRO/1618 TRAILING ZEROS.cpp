/* 
Sender:	WeakBlood
Submission time:	2025-02-11 20:38:08 +0200
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
This is a bit tricky, if we take a calculator and start doing factorial from 1 till our calculator explodes, we will notice a weird pattern, 
every 5 products a trailing zero appears, every 25 products a trailing zero appears etc, this means that 
we have in our N (n = log₅(N)) Σⁿₖ₌1 OF 5^k  or in simpler terms: ( N/(5^1)+ N/(5^2)...N/(5^K)) trailing zeros.
*/

//

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
        int trailingZeros = 0;
        ll exp = 5;
        while(exp <= N){
            trailingZeros += N / exp;
            exp*=5;
        }
        cout << trailingZeros << '\n';
    }
    return 0;
}
