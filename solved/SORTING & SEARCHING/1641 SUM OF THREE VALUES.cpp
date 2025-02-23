/* 
Sender:	WeakBlood
Submission time:	2025-02-23 11:34:39 +0200
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
For this problem a naive approach would take cubic time, so intsead we can try to optimize 
this algorithm by mapping for each value the indexes in which it appears, 
we can achieve this in N logₙ by creating a map with a vector in each number that store all the indexes so that we can search for the third value directly
in logₙ.
Once we have done this we could just run the naive algorithm with this optimization and get O(N^2 logₙ) but this would still NOT pass,
so another optimization we can make is sorting the numbers and setting a bound to the first number that exceeds X-firstValue this is, because 
if there are 2 other numbers they must be at least 1 but strictly less than X-firstValue.
The last optimization we can make on this algorithm is saving the value of the min and max out of all the numbers in the vector and say
if min*3 is strictly greater than X this means that is impossible because no matter what you are going to sum 3 values will exceed X, 
same goes for max*3 because if it is strictly less than X no matter what you the 3 values you sum are you will always get a value that is less than X,
apply the same 2 principles when searching for the second value by doing firstValue-min*2 and firstValue-mx*2 and you will get a much lower amortized complexity 
that allows to pass all test cases even if the overall time complexity remains 
O(N^2 logₙ);
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
        int N,X;
        cin >> N >> X;
        vector<array<int,2>> v(N);
        map<int,vector<int>> mapping;
        ll mx = 0;
        ll mn = 0;
        for(int i = 0; i < N; i++){
            ll a;
            cin >> v[i][0];
            v[i][1]=i;
            mapping[v[i][0]].push_back(i);
            mx = max(mx,static_cast<ll>(v[i][0]));
            mn = min(mn,static_cast<ll>(v[i][0]));

        }

        if(N < 3 || mx*3 < X || mn*3 > X){
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }

        sort(v.begin(),v.end());
        bool found = false;
        int bound0 = lower_bound(v.begin(),v.end(),array<int,2>{X,0})-v.begin();

        for(int i = 0; i < bound0 && !found; i++){
            int key1 = X-v[i][0];
            if(key1-mn <= 0 || key1-mx*2 > 0) continue;
            auto it= lower_bound(v.begin(),v.end(),array<int,2>{key1,0});
            int bound = it-v.begin();
            for(int j = 0; j < bound && !found; j++){
                int key2 = key1-v[j][0];
                if(key2 < 0 || i == j) continue;
                int req = 1;
                if(key2 == v[i][0]) req++;
                if(key2 == v[j][0]) req++;
                if(mapping[key2].size() >= req){
                    array<int,3> ans = {v[i][1],v[j][1],-1};
                    for(int u:mapping[key2]){
                        if(u != ans[0] && u != ans[1]){
                            ans[2]=u;
                            break;
                        }
                    }
                    for(int a:ans)cout << a+1 << ' ';
                    found = true;
                }
            }
        }
        if(!found) cout << "IMPOSSIBLE \n";
    }
    return 0;
}
