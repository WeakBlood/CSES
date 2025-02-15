/* 
Sender:	WeakBlood
Submission time:	2025-02-15 22:21:57 +0200
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
For this problem we will use a multiset instead of multiset, this is because multiset allows us to perform 
inserts and deletions in O(logₙ), in this case we will use "auto l = apartaments.lower_bound(a-K);" which points to the first
number that is more than or equal to x, if apartaments.end() != l is for being sure that there is at least one number that is more than a-K, 
once you know that just check if this number is less thank a+k.

*/

//IMPORTANT: When using multiset if you want to remove only ONE occurrence of an element you must you erase in combination with a POINTER.
// Example for removing only one istance of 8 from the set s = {8,8,9}; s.erase(s.find(8)) [ the set now will be s = {8,9}]
// if you perform s.erase(8) the set will be s = {9};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int T;
    T = 1;
    while(T--){
        int N,M,K;
        cin >> N >> M >> K;
        vector<int> applicants(N);
        for(int i = 0; i < N; i++) cin >> applicants[i];

        multiset<int> apartaments;
        for(int i = 0; i < M; i++){
            int a;
            cin >> a;
            apartaments.insert(a);
        }

        sort(applicants.begin(),applicants.end()); // must try to not sort after XD 

        int ans = 0;
        for(int a:applicants){
            if(apartaments.empty()) break;
            auto l = apartaments.lower_bound(a-K);
            if(apartaments.end() != l && *l <= a+K){
                apartaments.erase(l);
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
