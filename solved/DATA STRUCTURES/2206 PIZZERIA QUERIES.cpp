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
struct SegmentTree{
    int N;
    vector<ll> tree;
    SegmentTree(const vector<ll> &v){
        N = v.size();
        tree.resize(N*2,LLONG_MAX);
        for(int i = 0; i < N; i++){
            tree[i+N] = v[i];
        }
        for(int i = N-1; i > 0; i--){
            tree[i]=min(tree[i<<1],tree[i<<1|1]);
        }
    }
 
    ll query(int l, int r){
        ll ans = LLONG_MAX;
 
        for(l+=N,r+=N; l < r; l>>=1,r>>=1){
            if(l&1) ans=min(ans,tree[l++]);
            if(r&1) ans=min(ans,tree[--r]);
        }
        return ans;
    }
 
    void update(int pos, ll val){
        for(tree[pos+=N]=val; pos > 1; pos>>=1){
            tree[pos>>1]=min(tree[pos],tree[pos^1]);
        }
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int N,Q;
    cin >> N >> Q;
 
    vector<ll> v(N);
    vector<ll> left(N),right(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
        left[i]=v[i]+i;
        right[i]=v[i]+(N-i+1);
    }
    SegmentTree leftoTree(left);
    SegmentTree rightoTree(right);
    while(Q--){
        int type;
        cin >> type;
        if(type == 1){
            int pos;
            ll x;
            cin >> pos >> x;
            pos--;
            v[pos]=x;
            left[pos]=v[pos]+pos;
            right[pos]=v[pos]+(N-pos+1);
            leftoTree.update(pos,left[pos]);
            rightoTree.update(pos,right[pos]);
        } else{
            int pos;
            cin >> pos;
            pos--;
            
            ll ans = v[pos];
            ll l = leftoTree.query(pos+1,N);
            l-=pos;
            ll r = rightoTree.query(0,pos);
            r-=(N-pos+1);
            
            
            ans=min({ans,l,r});
            cout << ans << '\n';
        }
    }
    return 0;
}
