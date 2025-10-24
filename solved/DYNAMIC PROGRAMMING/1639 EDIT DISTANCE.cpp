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
        string s,u;
        cin >> s >> u;
        int N = s.size(), M = u.size();
        vector<int> prev(M+1,0), actual(M+1,0);
        for(int j = 0; j <= M; j++){
            prev[j]=j;
        }
        for(int i = 1; i <= N; i++){
            actual[0]=i; // this is because if you remove ALL OF THE CHARS you end up with just i chars to remove left :))
            for(int j = 1; j <= M; j++){
                if(s[i-1] == u[j-1]){
                    actual[j]=prev[j-1];
                } else{
                    actual[j]=1+min({prev[j],prev[j-1],actual[j-1]});
                }
            }
            prev=actual;
        }
        cout << actual[M] << '\n';
    }
    return 0;
}
