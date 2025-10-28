/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
using namespace std;

//!!!EXPLANATION!!!:
/* 

*/

//Cases
struct FenwickMax{
    // Range [0,r]

    vector<int> bit;
    int N;
    FenwickMax(int N):N(N){
        bit.assign(N,0);
    }


    int query(int r){
        int ans = 0;
        for(; r >= 0; r = (r&(r+1))-1){
            ans=max(ans,bit[r]);
        }
        return ans;
    }

    void update(int idx, int val){
        for(; idx < N; idx = idx |(idx+1)){
            bit[idx]=max(bit[idx],val);
        }
    }
};
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
        vector<int> v(N);
        for(int i = 0; i < N; i++){
            cin >> v[i];
        }
        vector<int> c = v;
        sort(c.begin(),c.end());
        vector<int> ranker = {c[0]};
        for(int i = 1; i < N; i++){
            if(c[i]!=c[i-1]) ranker.push_back(c[i]);
        }
        
        FenwickMax fMax(ranker.size());
        int ans = 0;
        for(int i = 0; i < N; i++){
            int id = lower_bound(ranker.begin(),ranker.end(),v[i])-ranker.begin();
            int prev = fMax.query(id-1); 
            fMax.update(id,prev+1);
            ans=max(ans,prev+1);
        }
        cout << ans << '\n';
    }
    return 0;
}
