/*Sender:	WeakBlood
Submission time:	2025-02-10 16:56:38 +0200
Language:	C++ (C++17)
Status:	READY
Result:	ACCEPTED*/
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
