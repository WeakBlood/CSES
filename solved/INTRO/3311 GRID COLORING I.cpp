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
    int N,M;
    cin >> N >> M;
    vector<vector<char>> grid(N,vector<char>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }
    char options[4] = {'A','B','C','D'};

    bool ans = true;
    for(int i = 0; i < N  && ans; i++){
        for(int j = 0; j < M && ans; j++){
            char l = j-1 >= 0 ? grid[i][j-1]:'-';
            char u = i-1 >= 0 ? grid[i-1][j]:'-';
            ans = false;
            for(int k = 0; k < 4 && !ans; k++){
                if(options[k]!=l && options[k]!=u && options[k]!=grid[i][j]){
                    grid[i][j]=options[k];
                    ans = true;
                }
            }
            if(!ans) cout << j;
        }
    }

    if(!ans){
        cout << "IMPOSSIBLE" << '\n';
    } else{
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
