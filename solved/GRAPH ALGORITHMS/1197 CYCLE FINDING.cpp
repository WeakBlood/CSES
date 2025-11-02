/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
const ll inf = LLONG_MAX;
using namespace std;

//!!!EXPLANATION!!!:
/* 

*/

//Cases

struct Edge{
    int u,v;
    ll w;
};

int bellmanFord(int N, vector<Edge> &edges, vector<int> &parent, vector<ll> &distances){
    distances[0]=0;
    for(int i = 0; i < N; i++){
        for(auto [u,v,w]:edges){
            if(distances[u]!=inf && distances[u]+w < distances[v]){
                parent[v]=u;
                distances[v]=distances[u]+w;
                if(i==N-1) return u;
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int T = 1;
    while(T--){
        int N,M;
        cin >> N >> M;
        vector<Edge> edges(M);
        vector<vector<int>> graph(N);
        for(int i = 0; i < M; i++){
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
            edges[i].u--;
            edges[i].v--;
            graph[edges[i].u].push_back(edges[i].v);
        }
        vector<int> parent(N,-1);
        vector<ll> distances(N,inf);
        vector<bool> processed(N,false);
        queue<int> q;
        for(int i = 0; i < N; i++){
            if(processed[i]) continue;
            processed[i]=true;
            distances[i]=0;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int u:graph[node]){
                    if(!processed[u]){
                        q.push(u);
                        processed[u]=true;
                    }
                }
            }
        }
        int endCycle = bellmanFord(N,edges,parent,distances);
        
        if(endCycle!=-1){
            int x = parent[endCycle];
            int c = 0;
            cout << "YES" << '\n';
            
            vector<int> path;
            set<int> s;
            int starter = -1;
            while(c < 1){
                if(s.count(x)){
                    starter = x;
                    c++;
                }
                else s.insert(x);
                path.push_back(x);
                x = parent[x];
            }
            
            reverse(path.begin(),path.end());
            int n = path.size();
            bool started = false;
            for(int i = 0; i < n; i++){
                if(path[i]==starter){
                    cout << path[i]+1 << ' ';
                    if(started) break;
                    else started = true;
                } else if(started) cout << path[i]+1 << ' ';
            }
            cout << '\n';
        } else{
            cout << "NO" << '\n';
        }
        
    }
    return 0;
}
