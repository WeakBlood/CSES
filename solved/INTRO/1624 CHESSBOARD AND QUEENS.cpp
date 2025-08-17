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
int dirs[8][2] = {{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
void dp(int count, int i, vector<vector<char>> grid, int &ans){
    if(count == 8){
        ans++;
        return;
    }
    if(i >= 8) return;

    for(int j = 0; j < 8; j++){
        if(grid[i][j]=='*' || grid[i][j]=='!')continue;
        vector<vector<char>> copyG = grid;
        bool ok = true;
        copyG[i][j]='!';
        for(int k = 0; k < 8 && ok; k++){
            int nI = i+dirs[k][0];
            int nJ = j+dirs[k][1];
            while(nI < 8 && nJ < 8 && nI >= 0 && nJ >= 0 && ok){
                if(copyG[nI][nJ]=='!') ok=false;
                nI+=dirs[k][0];
                nJ+=dirs[k][1];
            }
        }
        if(ok) dp(count+1,i+1,copyG,ans);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int T;
    T = 1;
    while(T--){
        int N = 8;
        vector<vector<char>> grid(N,vector<char>(N));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> grid[i][j];
            }
        }   

        
        int ans = 0;
        dp(0,0,grid,ans);
        cout << ans << '\n';
    }
    return 0;
}
