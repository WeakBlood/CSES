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
 
        vector<int> components;
 
        queue<int> q;
        vector<bool> processed(N,false);
        for(int i = 0; i < N; i++){
            if(processed[i]) continue;
            processed[i]=true;
            components.push_back(i);
            q.push(i);
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
        }
        cout << components.size()-1 << '\n';
        int cp = components.size();
        for(int i = 1; i < cp; i++){
            cout << components[i-1]+1 << ' ' << components[i]+1 << '\n';
        }
    }
    return 0;
}
