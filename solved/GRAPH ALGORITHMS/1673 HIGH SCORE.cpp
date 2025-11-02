/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
const ll BIGMAX = LLONG_MAX;
using namespace std;

//!!!EXPLANATION!!!:
/* 

*/

//Cases

pair<ll,vector<int>> bellManFord(int N, vector<array<ll,3>> &edges, int src){
    vector<ll> distances(N,BIGMAX);
    vector<int> plagued;
    distances[src]=0;
    for(int i = 0; i < N; i++){
        for(auto[u,v,w]:edges){
            if(distances[u]!=BIGMAX && distances[u]+w < distances[v]){
                if(i==N-1){
                    plagued.push_back(u);
                    plagued.push_back(v);
                }
                distances[v]=distances[u]+w;
            }
        }
    }
    return {-distances[N-1],plagued};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif  

    int N,M;
    cin >> N >> M;

    vector<array<ll,3>> edges(M);
    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++){
        for(int k = 0; k < 3; k++){
            cin >> edges[i][k];
            if(k<2) edges[i][k]--;
            else edges[i][k] = -edges[i][k];
        }
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    auto[dist,plagued] = bellManFord(N,edges,0);

    if(plagued.empty()){
        cout << dist << '\n';
    } else{
        queue<int> q;
        vector<bool> processed(N,false);
        for(int u:plagued){
            q.push(u);
            processed[u]=true;
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int u:graph[node]){
                if(!processed[u]){
                    processed[u]=true;
                    q.push(u);
                }
            }
        }
        if(processed[N-1]) cout << -1 << '\n';
        else cout << dist << '\n';
    }
    
    return 0;
}
