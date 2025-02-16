/* 
Sender:	WeakBlood
Submission time:	2025-02-16 12:42:15 +0200
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
WARNING: I OVERKILLED THE PROBLEM SO MY SOLUTION IS BY FAR THE WORST IN TERMS OF LENGHT BUT STILL.
For this problem i used the segmenTree for finding each time the best film to watch after this, 
( the best film is the one who allows me to watch the maximum amount of films in total ), so 
each time i search for it after doing binary search for finding the range i can check.
I will not explain the problem in-depth because as i said, this solution is not ETHICALLY correct.
This gives me a complexity of O(N logₙ) with just a bit... of overhead :) to be precise, O(N 3logₙ)
*/

//Cases


struct SegmentTree{
    int N;
    vector<int> tree;
    SegmentTree(int N):N(N){
        tree.resize(N*2);
    }   

    void update(int p, int val){
        for(tree[p+=N]=val; p > 0; p>>=1){
            tree[p>>1] = max(tree[p],tree[p^1]);
        }
    }

    int query(int l, int r){
        int mx = 0;
        for(l+=N, r+=N; l < r; l>>=1, r>>=1){
            if(l&1) mx=max(mx,tree[l++]);
            if(r&1) mx=max(mx,tree[--r]);
        } 
        return mx;
    }
};

int bin(const vector<array<int,2>> &ranges, int x, int l){
    l++;
    int r = ranges.size()-1;
    int ans = ranges.size();
    while(l <= r){
        int mid = l+(r-l)/2;
        if(ranges[mid][0] >= x){
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
    int T;
    T = 1;
    while(T--){
        int N;
        cin >> N;
        vector<array<int,2>> ranges(N);
        for(int i = 0; i < N; i++){
            cin >> ranges[i][0] >> ranges[i][1];
        }

        sort(ranges.begin(),ranges.end());

        SegmentTree rangeTree(N);
        int ans = 1;
        for(int i = N-1; i >= 0; i--){

            int l = bin(ranges,ranges[i][1], i);
            int v = 1;
            if(l != N) v+= rangeTree.query(l,N);
            rangeTree.update(i,v);
            ans = max(ans,v);
        }

        cout << ans << '\n';
    }

    return 0;
}
