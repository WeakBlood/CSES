/* 
Sender:	WeakBlood
Submission time:	2025-02-23 13:32:06 +0200
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
For this problem we are going to use a map for tracking the frequency in which a certain value appears, 
and if at any given moment the sum the prefix sum from to i-th value - X points to a value that has already appeared 
it means that we can form X from that value + our actual pfx, so add that to the answer.
Remember that in this version we must use a long long for storing the answer since we will go into negative values 
more often.

Time complexity O(N logₙ) 
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
        int N;
        ll X;
        cin >> N >> X;
        map<ll,int> freq;
        ll pfx = 0;
        freq[pfx]++;
        ll a;
        ll ans = 0;
        for(int i = 0; i < N; i++){
            cin >> a;
            pfx+=a;
            ans+=freq[pfx-X];
            freq[pfx]++;
        }   
        cout << ans << '\n';
    }
    return 0;
}
