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

bool dfs(int node, int parent, const vector<vector<int>> &graph, vector<bool> &processed, deque<int> &path){
    path.push_back(node);
    if(processed[node]) return true;
    processed[node] = true;
    for(int u:graph[node]){
        if(u == parent) continue;
        if(dfs(u,node,graph,processed,path)) return true;
    }
    path.pop_back();
    return false;
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

        deque<int> path;
        vector<bool> processed(N,false);
        bool done = false;
        for(int i = 0; i < N && !done ;i++){
            if(!processed[i] && dfs(i,i,graph,processed,path)){
                while(!path.empty()&& path.front() != path.back()) path.pop_front();
                if(path.size() <= 3) continue;
                cout << path.size() << '\n';
                for(int k:path){
                    cout << k+1 << ' ';
                }
                done = true;
                cout << '\n';
            }
        }
        if(!done) cout << "IMPOSSIBLE" << '\n';
    }
    return 0;
}
