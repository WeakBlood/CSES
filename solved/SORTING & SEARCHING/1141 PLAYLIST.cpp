/* 
Sender:	WeakBlood
Submission time:	2025-02-16 21:19:08 +0200
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
In this problem we will use a sliding window like approach, each time we want to add a new element we check if it exists already
in the current window, if it does then we reduce the window until we reach the previous occurrence of that element in the set (in this operation we need also to remove
all the elements in the range from the start of the window to the occurrence), then we memorize the max size we got among all the possible ones.
Each element gets iterated at most twice so the algorithm is pretty efficient.
Time complexity O(N logₙ);
*/

//Remember that if a key in a map is not initialized the value at that key will simply be zero, so you are allowed to directly erase for better performance <3

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
        map<int,int> freq;
        vector<int> v(N+1);
        int ans = 0;
        int l = 1;
        for(int i = 1; i <= N; i++){
            cin >> v[i];
            int f = freq[v[i]];
            if(f!= 0){

                for(int k = l; k < f; k++) freq.erase(v[k]);
                l = f+1;
            }
            freq[v[i]]=i;
            ans = max(i-l+1,ans);
        }
        cout << ans << '\n';
    }
    return 0;
}
