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


        priority_queue<array<ll,3>> q;
        vector<array<bool,2>> processed(N,{false,false});
        vector<array<ll,2>> distance(N,{inf,inf});
        distance[0][0]=0;
        q.push({0,0,0});
        while(!q.empty()){
            auto[w,node,t] = q.top();
            q.pop();
            if(processed[node][t]) continue;
            processed[node][t]=true;
            for(Edge u:graph[node]){
                if(t==0){
                    if(distance[node][t]+(u.w/2) < distance[u.des][1]){
                        distance[u.des][1]=distance[node][t]+(u.w/2);
                        q.push({-distance[u.des][1],u.des,1});
                    }
                }
                if(distance[node][t]+u.w < distance[u.des][t]){
                    distance[u.des][t]=distance[node][t]+u.w;
                    q.push({-distance[u.des][t],u.des,t});
                }
            }
            
        }
        cout << distance[N-1][1] << '\n';
    }
    return 0;   
}
