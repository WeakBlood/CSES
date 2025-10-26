/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
const int mod = 1e9+7;
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
    int N;
    cin >> N;
    int tot = (N*(N+1))/2;
    if(tot%2!=0){
        cout << 0 << '\n';
        return 0;
    } else{
        int target = tot/2;
        //cout << target << ' ';
        vector<int> actual(target+1,0);
        vector<int> previous(target+1,0);
        previous[0]=1;
        for(int k = 1; k < N; k++){
            for(int i = 0; i <= target; i++){
                actual[i]=(previous[i]+actual[i])%mod;
                if(i-k >= 0) actual[i] = (actual[i]+previous[i-k])%mod;
            }
            swap(previous,actual);
            actual.assign(target+1,0);
        }
        cout << previous[target] << '\n';
    }
    return 0;
}
