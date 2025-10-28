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
        vector<array<ll,3>> v(N+1);
        v[0]={0,0,0};
        for(int i = 1; i <= N; i++){
            for(int j = 0; j < 3; j++){
                cin >> v[i][j];
            }
        }

        sort(v.begin(),v.end());
        vector<ll> dp(N+1,0);
        vector<ll> maxThere(N+1,0);

        for(int i = N; i >= 0; i--){
            ll x = v[i][1];
            
            int l = i+1; 
            int r = N;
            while(l <= r){
                int mid = l+(r-l)/2;
                if(v[mid][0] <= x){
                    l = mid+1;
                } else{
                    r = mid-1;
                }
            }

            if(l!=N+1){
                dp[i]=maxThere[l];
            }   
            dp[i]+=v[i][2];
            if(i+1 <= N) maxThere[i]=maxThere[i+1];
            maxThere[i]=max(maxThere[i],dp[i]);
            //cout << dp[i] << ' ';
        }
        cout << dp[0] << '\n';

    }
    return 0;
}
