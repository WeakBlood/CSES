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
    int T;
    T = 1;
    while(T--){
        int N;
        cin >> N;
        for(int i = 0; i < (1<<N); i++){
            bitset<16> b(i^(i>>1));
            for(int k = N-1; k >=  0; k--) cout << b[k];
            cout << '\n';
        }
    }
    return 0;
}
