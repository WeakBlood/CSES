/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
using namespace std;

//!!!EXPLANATION!!!:
/* 
The explanation for this is really easy if you know what a set does, basically the idea is,
since the set is a data structures that does insertions in O(logₙ) and only 
ONE istance of each number is memorized even if you insert it multiple times.

Time complexity O(Nlogₙ);
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
        int N;
        cin >> N;
        set<int> s;
        for(int i = 0; i < N; i++){
            int a;
            cin >> a;
            s.insert(a);
        }
        cout << s.size() << '\n';
    }
    return 0;
}
