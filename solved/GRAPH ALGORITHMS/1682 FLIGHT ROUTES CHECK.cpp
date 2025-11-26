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

void dfs(int node, const vector<vector<int>> &graph, vector<bool> &processed,vector<int> &path){
    processed[node]=true;
    for(int u:graph[node]){
        if(!processed[u]) dfs(u,graph,processed,path);
    }
    path.push_back(node);
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
            if(!processed[i])dfs(i,graph,processed,path);
        }
        reverse(path.begin(),path.end());
        vector<vector<int>> components;
        processed.assign(N,false);
        for(int node:path){
            if(!processed[node]){
                vector<int> component = {};
                dfs(node,revGraph,processed,component);
                components.push_back(component);   
            }
        }

        if(components.size() > 1){
            cout << "NO" << '\n';
            cout << components[1][0]+1 << ' ' << components[0][0]+1 << '\n';
        } else{
            cout << "YES" << '\n';
        }

    }
    return 0;
}
