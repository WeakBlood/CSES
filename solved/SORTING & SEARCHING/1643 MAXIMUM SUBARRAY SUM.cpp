/* 
Sender:	WeakBlood
Submission time:	2025-02-16 13:54:10 +0200
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
The key for solving this problem is noting that the array must be contiguos and non empty, this means that if a number 
is greater than the number + previous you want that number to be the new start of your sub-array. 
Take for example v = {-1,-1,7,-1};  the first position will have -1 as answer because it's the only thing you can do but then 
the second will not have -2 but -1 because taking another -1 will decrease the value even more, and so on.
So the final s will be s = {-1,-1,7,6} ;
This gives out our time complexity of O(N);
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
        vector<ll> v(N+1);
        cin >> v[0];
        ll mx = v[0];
        for(int i = 1; i < N; i++){
            cin >> v[i];
            v[i]=max(v[i],v[i]+v[i-1]);
            mx=max(v[i],mx);
        }

        cout << mx << '\n';

    }
    return 0;
}
