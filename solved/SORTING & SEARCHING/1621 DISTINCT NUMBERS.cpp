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
    int N;
    cin >> N;
    set<int> s;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << '\n';
    return 0;
}
