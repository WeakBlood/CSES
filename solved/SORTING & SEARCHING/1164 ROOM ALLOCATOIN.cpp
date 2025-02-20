/* 
Sender:	WeakBlood
Submission time:	2025-02-20 18:20:18 +0200
Language:	C++ (C++17)
Status:	READY
Result:	ACCEPTED
*/
#include <bits/stdc++.h>

#define ll long long int
const int  inf =  1e9;
using namespace std;

//!!!EXPLANATION!!!:
/* 
In this problem, we can start by sorting our guests arrivals and departure times, 
once we do this, we can use a set for keeping track of which guests are in which room, 
we don't need to check for each room but rather for the departure times of the guests since 
with just that information we can check if there is someone who will leave the room empty before we arrive.
For doing this in code we use a set, as i said and in this set we memorize {endingTime,startingTime,idRoom}, 
when a guest arrives if by doing lower_bound i go higher than the start of the set it means that there is 
at least one guest which departure time is strictly less than my arrival time so i can take that room else 
i have to "create" another room.

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
    T = 1;
    while(T--){
        int N;
        cin >> N;
        
        vector<array<int,3>> ranges(N);
        for(int i = 0; i < N; i++){
            cin >> ranges[i][0] >> ranges[i][1];
            ranges[i][2]=i;
        }
        sort(ranges.begin(),ranges.end());
        set<array<int,3>> s;
        vector<int> ans(N,0);

        for(auto [a,b,i]:ranges){
            auto it = s.lower_bound({a,0,0}); // i search for the first room that has a guest which ending time is equal or bigger than my starting time.
            int roomNumber;
            if(s.begin() == it){
                // all guests will stay at their rooms on that day, so i have to create another room.
                roomNumber = s.size()+1;
            } else{
                // the guest at position it has not left their room yet, but the one before did.
                it--; // so we go one before and erase
                roomNumber = (*it)[2];
                s.erase(it);
            }
            ans[i]=roomNumber;
            s.insert({b,a,roomNumber});

        }
        cout << s.size() << '\n';
        for(int u:ans) cout << u << ' ';
        cout << '\n';

    }
    
    
    return 0;
}
