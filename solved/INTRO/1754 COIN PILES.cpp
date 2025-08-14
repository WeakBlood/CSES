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
    cin >> T;
    while(T--){
        int a,b;
        cin >> a >> b;
        while(a > 0 || b > 0){
            int maxi = max(a,b);
            int mini = min(a,b);
            int diff = maxi-mini;
            if(maxi == mini){
                if(maxi % 3 == 0){
                    a = 0;
                    b = 0;
                } else {
                    a = -1;
                    b = -1;
                }
            }
            else if(maxi >= diff*2 && mini >= diff){
                maxi-=(diff*2);
                mini-=diff;
                a = maxi;
                b = mini;
            } else {
                a = -1;
                b = -1;
            }
            
        }

        if(a != -1 && b != -1) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
