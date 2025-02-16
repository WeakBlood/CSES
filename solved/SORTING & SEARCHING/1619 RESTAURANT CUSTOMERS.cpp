/* 
Sender:	WeakBlood
Submission time:	2025-02-16 12:11:12 +0200
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
In this problem, i should have noticed that all the arrival and leaving times are distinct in order to use a shorter solution, 
So for solving this problem i used a combination of map and vector, since going from 0 to 1e9 and checking each time if something happens is not that efficient, 
we can just flag with the map the times when SOMETHING happens, and register if it is customer I joining, or customer I leaving, after we process all
actions of a given time, we can check who's left. There is no need to check the in between time ( the times where nothing happens ) because it 
will be the same in all of them.

Time complexity: O(N logₙ);
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
        int ans = 0;
        int active = 0;
        map<int,vector<int>> actions;

        int N;
        cin >> N;
        for(int i = 1; i <= N; i++){
            int a,b;
            cin >> a >> b;
            actions[a].push_back(i);
            actions[b].push_back(-i);
            // -i is for flagging an exit
        }

        for(auto [t,q]:actions){
            // t is the time this happens 
            // q is all the actions that happens
            for(int u:q){
                if(u >= 0) active++;
                else active--;
            }
            ans = max(active,ans);
        }
        cout << ans << '\n';
    }
    return 0;
}
