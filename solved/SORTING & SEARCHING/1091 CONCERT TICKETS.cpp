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
    int N,M;
    cin >> N >> M;
    multiset<int> tickets;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        tickets.insert(t);
    }

    for(int i = 0; i < M; i++){
        int customer;
        cin >> customer;
        if(!tickets.empty()){
            auto it = tickets.upper_bound(customer);
            if(it!=tickets.begin()){
                it--;
                cout << *(it) << '\n';
                tickets.erase(it);
            } else{
                cout << -1 << '\n';
            }
        } else{
            cout << -1 << '\n';
        }
    }
    return 0;
}
