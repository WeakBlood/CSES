/* 
Sender:	WeakBlood
Submission time:	2025-02-16 18:45:40 +0200
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
This is more of a math problem, here we need to know that the closest value for all elements in a vector, is the median of it, take 
for example v = {1,4,5,100,100} if we took the average as pivot to reach  instead of the median we would have 232 as answer, but if we did the same thing 
with the median which in this case is 5, we are going to have 195 as answer, which is the minimum possible.
This runs in time complexity O(N logₙ) since the easiest way to find the median of a vector is to sort it and point to the middle element.
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
        cin >> N;
        vector<ll> v(N);
        ll ans = 0;
        //ll sum = 0;
        for(int i = 0; i < N; i++) cin >> v[i];
        sort(v.begin(),v.end());
        for(int i = 0; i < N; i++){
            ans+=abs(v[N/2]-v[i]);
        }
        cout << ans << '\n';

    }
    return 0;
}
