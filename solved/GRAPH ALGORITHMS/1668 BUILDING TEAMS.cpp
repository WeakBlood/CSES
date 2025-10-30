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
        vector<vector<int>> graph(N);
        for(int i = 0; i < M; i++){
            int a,b;
            cin >> a >> b;
            a--; b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bool ok = true;
        vector<int> color(N,-1);    
        queue<int> q;
        for(int i = 0; i < N && ok; i++){
            if(color[i]!=-1) continue;
            q.push(i);
            color[i]=1;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int u:graph[node]){
                    if(color[u]==-1){
                        if(color[node]==1){
                            color[u]=2;
                        } else{
                            color[u]=1;
                        }
                        q.push(u);
                    } else if(color[u]==color[node]) ok = false;
                }
            }

        }

        if(ok){
            for(int u:color) cout << u << ' ';
        } else{
            cout << "IMPOSSIBLE" << '\n';
        }
    }
    return 0;
}
