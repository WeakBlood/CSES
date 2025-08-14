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
        
        string ss;
        cin >> ss;
        int N = ss.size();
        vector<char> s(ss.begin(),ss.end());    
        sort(s.begin(),s.end());
        vector<char> ans(N,'-');
        bool ok = true;
        int l = 0;
        for(int i = 0; i < N && ok; i++){
            if(s[i]==s[i+1]){
                ans[l]=s[i];
                ans[N-l-1]=s[i];
                i++;
                l++;
            } else if(N%2 != 0 && ans[N/2] == '-')ans[N/2]=s[i];
            else ok = false;
        }

        if(!ok) cout << "NO SOLUTION" << '\n';
        else {
            for(char c:ans) cout << c;
            cout << '\n';
        }
    }
    return 0;
}
