/* WeakBlood <3 */
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
#define f(a,b,c) for(int i = a; i < b; i+=c)
using namespace std;

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
        vector<int> freq(N+1,false);
        for(int i = 1; i < N; i++){
            int a;
            cin >> a;
            freq[a]=true;
        }

        f(1,N+1,1){
            if(!freq[i]){
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
