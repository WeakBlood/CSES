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
        int N,M;
        cin >> N >> M;
        vector<vector<char>> grid(N,vector<char>(M));
        vector<vector<bool>> processed(N,vector<bool>(M,false));
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> grid[i][j];
            }
        }

        int dirs[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        queue<array<int,2>> q;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(processed[i][j] || grid[i][j]!='.') continue;
                q.push({i,j});
                processed[i][j]=true;
                ans++;
                while(!q.empty()){
                    auto [i1,j1] = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++){
                        int nI = i1+dirs[k][0];
                        int nJ = j1+dirs[k][1];
                        if(nI >= 0 && nJ >= 0 && nI < N && nJ < M && !processed[nI][nJ] && grid[nI][nJ]=='.'){
                            processed[nI][nJ]=true;
                            q.push({nI,nJ});
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
