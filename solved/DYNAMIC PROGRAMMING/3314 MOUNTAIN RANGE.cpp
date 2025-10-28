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

struct SparseTable{
    int N;
    int lg;
    vector<int> logs;
    vector<vector<int>> table;

    SparseTable(int N,const vector<int> &v):N(N){
        logs.assign(N+1,0);
        for(int i = 2; i <= N; i++){
            logs[i]=1+logs[i>>1];
        }
        lg = logs[N]+1;

        table.assign(N,vector<int>(lg));

        for(int i = 0; i < N; i++){
            table[i][0]=v[i];
        }

        for(int i = 1; i < lg; i++){
            for(int j = 0; j+(1<<i)<=N; j++){
                table[j][i]=max(table[j+(1<<(i-1))][i-1],table[j][i-1]);
            }
        }
    }
    
    int query(int l, int r){
        int lg  = logs[r-l+1];
        return max(table[l][lg],table[r-(1<<lg)+1][lg]);
    }
};


struct SegmentTree{
    int N;
    vector<int> tree;

    SegmentTree(int N, const vector<int> &v):N(N){
        tree.resize(N*2,0);
        for(int i = 0; i < N; i++){
            tree[i+N]=v[i];
        }
        for(int i = N-1; i > 0; i--){
            tree[i]=max(tree[i<<1],tree[i<<1|1]);
        }
    }

    void update(int pos, int val){
        for(tree[pos+=N]=val; pos > 1; pos>>=1){
            tree[pos>>1]=max(tree[pos],tree[pos^1]);
        }
    }

    int query(int l, int r){
        int mx = 0;
        for(l+=N,r+=N; l < r; l>>=1,r>>=1){
            if(l&1)mx=max(mx,tree[l++]);
            if(r&1)mx=max(mx,tree[--r]);
        }
        return mx;
    }
};


int closeRight(int x, int id, SparseTable &kurwa, int N){
    if(id >= N-1) return -1;
    int l = id+1;
    int r = N-1;
    int ans = -1;
    while(l <= r){
        int mid = l+(r-l)/2;
        int q = kurwa.query(id+1,mid);
        if(x > q){
            ans = mid;
            l = mid+1;
        } else{
            r = mid-1;
        }
    }
    return ans;
}
int closeLeft(int x, int id, SparseTable &kurwa){
    if(id <= 0) return -1;
    int l = 0;
    int r = id-1;
    int ans = -1;
    while(l <= r){
        int mid = l+(r-l)/2;
        int q = kurwa.query(mid,id-1);
        if(x > q){
            ans = mid;
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int N;
    cin >> N;
    vector<int> v(N);
    vector<array<int,2>> subV(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
        subV[i]={v[i],i};
    }

    vector<int> dp(N,0);
    sort(subV.begin(),subV.end());
    SegmentTree bobre(N,dp); // fucking max o(log(n))
    SparseTable kurwa(N,v); // fucking max o(1) ::)))))) blazing fast woooooooooooo
    
    for(auto [x,i]:subV){   
        int l = closeLeft(x,i,kurwa);
        int r = closeRight(x,i,kurwa,N);
        if(l==-1){
            if(r!=-1){
                dp[i]=bobre.query(i,r+1);
            }
        } else if(r==-1){
            dp[i]=bobre.query(l,i);
        } else{
            dp[i]=bobre.query(l,r+1);
        }
        dp[i]++;
        bobre.update(i,dp[i]);
    }
    cout << bobre.query(0,N) << '\n';
    return 0;
}
