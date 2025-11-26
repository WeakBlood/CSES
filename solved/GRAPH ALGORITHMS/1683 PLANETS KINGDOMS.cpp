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

void dfs(int node, const vector<vector<int>> &graph, vector<bool> &processed, vector<int> &path, const int &k = -1){
    if(k!=-1) path[node]=k;
    processed[node]=true;
    for(int u:graph[node]){
        if(!processed[u]) dfs(u,graph,processed,path,k);
    }
    if(k==-1)path.push_back(node);
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
        vector<vector<int>> revGraph(N);
        for(int i = 0; i < M; i++){
            int a,b;
            cin >> a >> b;
            a--; b--;
            graph[a].push_back(b);
            revGraph[b].push_back(a);
        }

        vector<bool> processed(N,false);
        vector<int> path;
        for(int i = 0; i < N; i++){
            int node = i;
            if(!processed[node]) dfs(node,graph,processed,path);
        }

        reverse(path.begin(),path.end());
        processed.assign(N,false);
        vector<int> ans(N);
        int K = 0;
        for(int u:path){
            if(!processed[u]) dfs(u,revGraph,processed,ans,++K);
        }

        cout << K << '\n';
        for(int a:ans){
            cout << a << ' ';
        }
    }
    return 0;
}
