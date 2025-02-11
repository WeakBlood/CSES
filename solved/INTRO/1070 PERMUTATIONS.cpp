/* 
Sender:	WeakBlood
Submission time:	2025-02-11 18:44:38 +0200
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
This approach works because if we take x which is let's say even, x+1 is gonna be odd,
this means that every sequence of odd numbers is gonna have at least an absolute difference of 2 between adjiacent numbers, 
we can just reduce the problem to "OUTPUT ALL EVEN NUMBERS FROM 2 TO N AND ALL ODD NUMBERS FROM 1 TO N"
*/

//THE ONLY IMPOSSIBLE CASES ARE N = 2 AND N = 3

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
        int Odd = (N&1 ? N:N-1);
        int Even = (N&1 ? N-1:N);
        vector<int> odd,even;
        for(int i = Odd; i >= 1; i-=2) odd.push_back(i);
        for(int i = Even; i >= 1; i-=2) even.push_back(i);
        if(abs(odd.back()-Even) <= 1 && N != 1){
            cout << "NO SOLUTION" << '\n';
        } else{
            for(int u:odd) cout << u << ' ';
            for(int u:even) cout << u << ' ';
            cout << '\n';
        }
    }
    return 0;
}
