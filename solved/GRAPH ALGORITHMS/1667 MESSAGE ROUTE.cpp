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


        vector<bool> processed(N,false);
        vector<int> parent(N,-1);
        queue<int> q;
        q.push(0);
        processed[0]=true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int u:graph[node]){
                if(processed[u]) continue;
                processed[u]=true;
                parent[u]=node;
                q.push(u);
            }
        }
        if(processed[N-1]){
            //cout << "YES" << '\n';
            vector<int> path;   
            int node = N-1;
            while(node!=-1){
                path.push_back(node);
                node=parent[node];
            }
            reverse(path.begin(),path.end());
            cout << path.size() << '\n';
            for(int u:path) cout << u+1 << ' ';
        } else{
            cout << "IMPOSSIBLE" << '\n';
        }
    }
    return 0;
}
