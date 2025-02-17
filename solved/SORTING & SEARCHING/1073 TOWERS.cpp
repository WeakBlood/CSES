/* 
Sender:	WeakBlood
Submission time:	2025-02-17 22:45:08 +0200
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
For solving this problem we need to understand that each time we have to place 
a new cube THE BEST OPTION IF POSSIBLE IS ALWAYS TO PUT IT ON TOP OF 
THE TOWER THAT IS CLOSER TO THE VALUE OF THE NEW CUBE.
Well, why is that ? 
If we apply this greedy approach we will be sure that we optimize the usage of a single tower as much as possible.
For simulating this process we will need just a multiset of integers ( which as you know stores istances of elements [ even the same element more than once ] 
with insertions and deletions in just logₙ ) for rappreseting the top of each tower ( we don't need to store the whole tower because the elements under the top have no value for the solution ).
Then, each time we have a new cube we search for tower that has a top strictly greater than our cube and replace that top with the size of our cube.
If we don't find any tower whose top is strictly greater than our cube we create a new tower with our cube as top size.

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
        cin >> N;
        multiset<int> tops;
        for(int i = 0; i < N; i++){
            int a;
            cin >> a;
            auto it = tops.upper_bound(a);
            if(it != tops.end()){
                tops.erase(it);
            } 
            tops.insert(a);
        }
        cout << tops.size() << '\n';
    }
    return 0;
}
