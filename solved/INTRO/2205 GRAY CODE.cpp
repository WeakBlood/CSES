/* 
Sender:	WeakBlood
Submission time:	2025-02-13 19:47:10 +0200
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
There are 2ᴺ combinations to output, the problem requires you output those combination in a specific order "each adjacent combination must have only 1 different bit",
to achieve this, we can output each number from 0 to P (P = 2ᴺ) with following formula (x^(x>>1)) so x XOR x/2;
if we have 2, 2^(2/2) = 3, which in binary is 10^01 = 11 which is the correct number to output next 1 which was 01^00 = 01. 
This has complexity O(2ᴺ);
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
    int p = pow(2,N);
    for(int i = 0; i < p; i++){
        bitset<16> b(i^(i>>1));
        for(int k = N-1; k >= 0; k--) cout << b[k];
        cout << '\n';
    }

    return 0;
}
