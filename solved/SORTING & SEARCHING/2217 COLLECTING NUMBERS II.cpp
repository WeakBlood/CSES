/* 
Sender:	WeakBlood
Submission time:	2025-02-16 20:58:37 +0200
Language:	C++ (C++17)
Status:	READY
Result:	ACCEPTED
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
using namespace std;

//!!!EXPLANATION!!!:
/* 
After like an hour trying to figure out how to still solve it in linear time without to many if, i came up with this implementation, 
the key here is understanding that if are x, and you were in a position after x-1 you were not counted as a new round,
so now you COULD be counted, so do round++, the same goes if you were in a position before x+1. 
After swapping you check once again, if you now are in a position in which x-1 is before you then need fewer rounds, same for x+1.

Time complexity O(N) YEAAAAAAA;
*/

//Cases
void verify(int b, const vector<int> &v, const vector<int> &idx, int &rounds,int rem, int x = -1){
    if(idx[v[b]] >= idx[v[b]-1] && v[b]-1 != x){
        rounds+=rem;
    }
    if(idx[v[b]] <= idx[v[b]+1] && v[b]+1 != x){
        rounds+=rem;
    }
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
        int N,Q;
        cin >> N >> Q;
        vector<int> v(N);
        vector<int> idx(N+2,-1);
        int rounds = 0;
        for(int i = 0; i < N; i++){
            cin >> v[i];
            idx[v[i]]=i;
            if(v[i] == 1 || (idx[v[i]-1] == -1)) rounds++; 
        }
        idx[N+1] = inf;
        //cout << rounds << '\n';
        while(Q--){
            int a,b;
            cin >> a >> b;
            a--; b--;
            verify(a,v,idx,rounds,1);
            verify(b,v,idx,rounds,1,v[a]);
            idx[v[a]]=b;
            idx[v[b]]=a;
            swap(v[a],v[b]);
            verify(a,v,idx,rounds,-1);
            verify(b,v,idx,rounds,-1,v[a]);
            cout << rounds << '\n';
        }

    }
    return 0;
}
