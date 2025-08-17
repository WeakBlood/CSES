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
    int N;
    cin >> N;
    vector<vector<int>> dists(N,vector<int>(N,-1));
    queue<array<int,2>> q;
    dists[0][0]=0;
    int dirs[8][2] = {{-2,-1},{-2,1},{2,-1},{2,1},{1,2},{-1,2},{1,-2},{-1,-2}};
    q.push({0,0});
    // bfs this shit and go the fuck away omg taking even O(N*2) fucking unreal 
 
    while(!q.empty()){
        int i = q.front()[0];
        int j = q.front()[1];
        q.pop();
        //cout << i << ' ' << j << '\n';
        for(int k = 0; k < 8; k++){
            int nI = i+dirs[k][0];
            int nJ = j+dirs[k][1];
            if(nI >= 0 && nJ >= 0 && nI < N && nJ < N){
                if(dists[nI][nJ]==-1){
                    dists[nI][nJ]=dists[i][j]+1;
                    q.push({nI,nJ});
                }
            }
        }
    }
 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << dists[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}