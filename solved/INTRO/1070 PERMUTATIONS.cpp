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
        if(N == 3 || (N == 2)){
            cout << "NO SOLUTION" << '\n';
            continue;
        }

        for(int i = 2; i <= (N%2 != 0 ? N-1:N); i+=2) cout << i << ' ';
        for(int i = 1; i <= (N%2 == 0 ? N-1:N); i+=2) cout << i << ' ';
    }
    return 0;
}
