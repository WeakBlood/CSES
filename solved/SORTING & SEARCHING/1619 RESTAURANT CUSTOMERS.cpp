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
    map<int,int> freq;
    
    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;
        freq[a]++;
        freq[b]--;
    }

    int ans = 0;
    int sum = 0;
    for(auto [time,count]: freq){
        sum+=count;
        ans = max(ans,sum);
    }   
    cout << ans << '\n';
    return 0;
}
