/* 
Sender:	WeakBlood
Submission time:	2025-02-23 12:45:47 +0200
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
Before reading this solution you should consider reading the solution for SUM OF THREE VALUES for better understanding, 
so, the naive approach for this would be O(N⁴) that would not pass,
so, after making the same optimization made for sum3 by setting specific ranges to check with lower_bound 
we can also set the starting point which is the first number that is at least X/4 since we need 4 values to make X, 
but another optimization needed for those specific test cases is reducing the number of repetitions of the same number to at max 4, 
since we need 4 values for making x if we have v = {4,4,4,4,4} or {4,4,4,4} the answer will be the excact same. 
For achieving this we just sort the original vector and add at most 4 repetitions of the same number with it's different indexes, 
else we just skip it, this concept can be applied for both sum3 and sum2 but since is not needed i didn't even thinked of it.
As for the time complexity even if it is O(N^3 logₙ) it has a much lower amortized complexity that allows us to pass all test cases.

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
        int N,X;
        cin >> N >> X;
        vector<array<ll,2>> original(N);
        map<ll,vector<int>> mapping;
        ll mx = 0;
        ll mn = 0;
        for(int i = 0; i < N; i++){
            cin >> original[i][0];
            original[i][1]=i;
            mapping[original[i][0]].push_back(i);
            mx = max(mx,static_cast<ll>(original[i][0]));
            mn = min(mn,static_cast<ll>(original[i][0]));
 
        }
 
        if(N < 3 || mx*4 < X || mn*4 > X){
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
 
        sort(original.begin(),original.end());
        vector<array<ll,2>> v;
        for(int i = 0; i < N; i++){
            if(i < 3 || (original[i-3][0] != original[i][0])){
                v.push_back({original[i]});
            }   
        }
        bool found = false;
        int bound0 = lower_bound(v.begin(),v.end(),array<ll,2>{X,0})-v.begin();
        int l0 = lower_bound(v.begin(),v.end(),array<ll,2>({X/4,0}))-v.begin();
        for(int i = l0; i < bound0 && !found; i++){
            array<ll,3> keys;
            keys[0] = X-v[i][0];
            if(keys[0]-mn*2 <= 0 || keys[0]-mx*3 > 0) continue;
            auto it= lower_bound(v.begin(),v.end(),array<ll,2>{keys[0],0});
            int bound = it-v.begin();
            int l = lower_bound(v.begin(),v.end(),array<ll,2>{keys[0]/3,0})-v.begin();
            for(int j = l; j < bound && !found; j++){
                keys[1]= keys[0]-v[j][0];
                if(keys[1] < 0 || i == j || keys[1]-mn <= 0 || keys[1]-mx*2 > 0) continue;
                int bound1 = lower_bound(v.begin(),v.end(),array<ll,2>{keys[1],0})-v.begin();
                int l1 = lower_bound(v.begin(),v.end(),array<ll,2>{keys[1]/2,0})-v.begin();
                for(int k = l1; k < bound1 && !found; k++){
                    keys[2]=keys[1]-v[k][0];
                    if(k == i || k == j || keys[2] <= 0 || keys[2]-mx > 0) continue;
                    int req = 1;
                    if(keys[2] == v[i][0]) req++;
                    if(keys[2] == v[j][0]) req++;
                    if(keys[2] == v[k][0]) req++;
                    if(mapping[keys[2]].size() >= req){
                        array<int,4> ans = {v[i][1],v[j][1],v[k][1],-1};
                        for(int u:mapping[keys[2]]){
                            if(u != ans[0] && u != ans[1] && u != ans[2]){
                                ans[3]=u;
                                break;
                            }
                        }
                        for(int a:ans)cout << a+1 << ' ';
                        found = true;
                    }
                }

            }
        }
        if(!found) cout << "IMPOSSIBLE \n";
    }
    return 0;
}