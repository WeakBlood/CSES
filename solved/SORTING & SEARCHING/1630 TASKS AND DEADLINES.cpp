/* 
Sender:	WeakBlood
Submission time:	2025-02-22 21:55:17 +0200
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
The thing that make this problem easy is that tou just need to know that no matter what is the deadline you must always choose to complete 
the one with the minimal duration as soon as possible if the reward is calculated by (DeadLine-Time) so this problem can be solved
by sorting the vector only because of this particular thing.
Time complexity: O(N logₙ)
*/

//Cases

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int T;
    T=1;
    while(T--){
        int N;
        cin >> N;
        vector<array<ll,2>> tasks(N);
        for(int i = 0; i < N; i++){
            cin >> tasks[i][0] >> tasks[i][1];
        }
        sort(tasks.begin(),tasks.end());


        ll ans = 0;
        ll time = 0;
        for(int i = 0; i < N; i++){
            time+=tasks[i][0];
            ans+=(tasks[i][1]-time);
        }
        cout << ans << '\n';
    }
    return 0;
}
