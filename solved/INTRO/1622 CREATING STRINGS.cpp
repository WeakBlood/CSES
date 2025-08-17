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
        string s;
        cin >> s;

        sort(s.begin(),s.end());
        vector<string> ans;
        do{
            ans.push_back(s);
        }   
        while(next_permutation(s.begin(),s.end()));

        cout << ans.size() << '\n';
        for(string g:ans){
            cout << g << '\n';
        }
    }
    return 0;
}
