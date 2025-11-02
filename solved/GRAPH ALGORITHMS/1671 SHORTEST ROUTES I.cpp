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

struct Edge{
    int des;
    ll w;
};
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

        vector<vector<Edge>> graph(N);
        for(int i = 0; i < M; i++){
            int a,b;
            ll w;
            cin >> a >> b >> w;
            a--; b--;
            graph[a].push_back({b,w});
        }


        
        vector<ll> distance(N,BIGMAX);
        vector<bool> processed(N,false);
        priority_queue<array<ll,2>> q;
        distance[0]=0LL;
        q.push({0,0});
        while(!q.empty()){
            int node = q.top()[1];
            q.pop();
            if(processed[node]) continue;
            processed[node]=true;
            for(Edge u:graph[node]){
                if(distance[node]+u.w < distance[u.des]){
                    distance[u.des]=distance[node]+u.w;
                    q.push({-distance[u.des],u.des});
                }
            }
        }

        for(ll d:distance){
            cout << d << ' ';
        }
        cout << '\n';
    }
    return 0;
}
