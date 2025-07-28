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
    string s;
    cin >> s;
    
    int N = s.size();
    int ans = 1;
    int ref = 0;
    for(int i = 1; i < N; i++){
        if(s[ref] != s[i]) ref = i;
        ans = max(ans,i-ref+1);
    }
    cout << ans << '\n';
    return 0;
}