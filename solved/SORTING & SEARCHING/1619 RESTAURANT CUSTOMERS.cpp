/* 
Sender:	WeakBlood
Submission time:	2025-02-16 11:57:59 +0200
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
For this problem we will need a multiset for storing all the tickets and the upper_bound function which returns the first the first element strictly greater than a certain
target x, insertions, deletions and upper_bound on multiset are O(logₙ) so each time we have a new customer we search for the first ticket that exceeds their maximum badget,
if the first one already exceedes it, it means that there are NO solutions and all tickets are above the customer badget, in all other cases, we can go one ticket behind
and give that to them since it will be the closest to X.
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
        int N,Q;
        cin >> N  >> Q;

        multiset<int> tickets;
        while(N--){
            int t;
            cin >> t;
            tickets.insert(t);
        }

        while(Q--){
            int X;
            cin >> X;
            auto it = tickets.upper_bound(X);
            if(tickets.begin() == it){
                cout << -1 << '\n';
            } else{
                it--;
                cout << *it << '\n';
                tickets.erase(it);
            }
        }
    }
    return 0;
}
