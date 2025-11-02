/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
const ll BIGMAXN = LLONG_MAX;
using namespace std;

//!!!EXPLANATION!!!:
/* 

*/

//Cases

void floydWarshall(vector<vector<ll>> &mtx){
    int N = mtx.size();
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(mtx[i][k]!=BIGMAXN && mtx[k][j]!=BIGMAXN){
                    mtx[i][j]=min(mtx[i][j],mtx[i][k]+mtx[k][j]);
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int N,M,Q;
    cin >> N >> M >> Q;

    vector<vector<ll>> mtx(N,vector<ll>(N,BIGMAXN));
    for(int i = 0; i < N; i++){
        mtx[i][i]=0LL;
    }
    for(int i = 0; i < M; i++){
        int a,b;
        ll w;
        cin >> a >> b >> w;
        a--; b--;
        mtx[a][b]=min(mtx[a][b],w);
        mtx[b][a]=min(mtx[b][a],w);
    }
    floydWarshall(mtx);
    while(Q--){
        int a,b;
        cin >> a >> b;
        a--; b--;
        if(mtx[a][b]==BIGMAXN) cout << -1 << '\n';
        else cout << mtx[a][b] << '\n';
    }
    return 0;
}
