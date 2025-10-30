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
        int startI,startJ,endI,endJ;
        vector<vector<char>> grid(N,vector<char>(M));
        vector<vector<bool>> processed(N,vector<bool>(M,false));
        vector<vector<char>> parent(N,vector<char>(M,'?'));
        vector<vector<array<int,2>>> p(N,vector<array<int,2>>(M,{-1,-1}));
        int dirs[4][2] = {{0,-1},{-1,0},{1,0},{0,1}};
        char eq[4] = {'L','U','D','R'};
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> grid[i][j];
                if(grid[i][j]=='A'){
                    startI = i;
                    startJ = j;
                } 
                if(grid[i][j]=='B'){
                    endI = i;
                    endJ = j;
                }
            }
        }

        queue<array<int,2>> q;
        q.push({startI,startJ});
        processed[startI][startJ]=true;
        while(!q.empty()){
            auto[i,j]=q.front();
            q.pop();
            if(i==endI && endJ== j) break;
            for(int k = 0; k < 4; k++){
                int nI = i+dirs[k][0];
                int nJ = j+dirs[k][1];
                if(nI >= 0 && nJ >= 0 && nI < N && nJ < M && !processed[nI][nJ] && grid[nI][nJ]!='#'){
                    processed[nI][nJ]=true;
                    parent[nI][nJ]=eq[k];
                    p[nI][nJ]={i,j};
                    q.push({nI,nJ});
                }
            }
        }

        if(!processed[endI][endJ]){
            cout << "NO" << '\n';
            continue;
        }
        vector<char> path;
        int i = endI, j = endJ;
        while(p[i][j][0] != -1){
            path.push_back(parent[i][j]);
            array<int,2> n = p[i][j];
            i = n[0];
            j = n[1];
        }
        reverse(path.begin(),path.end());
        cout << "YES" << '\n';
        cout << path.size() << '\n';
        for(char p:path){
            cout << p;
        }
        cout << '\n';
    }
    return 0;
}
