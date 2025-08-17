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
        int N,a,b;
        cin >> N >> a >> b;
        vector<int> alice,bob;
        if(a+b > N){
            cout << "NO" << '\n';
            continue;
        } 
 
        if(a == 0 && b == 0){
            cout << "YES" << '\n';
            for(int i = 1; i <= N; i++){
                cout << i << ' ';
            }
            cout << '\n';
            for(int i = 1; i <= N; i++){
                cout << i << ' ';
            }
            cout << '\n';
            continue;
        }
        if(a+b < N){
            while(N > 0 && (a+b) < N){
                alice.push_back(N);
                bob.push_back(N);
                N--;
            }
        }
 
        if(a < 1 || b < 1){
            cout << "NO" << '\n';
            continue;
        }
        if(a >= b){
            int l = a;
            int r = N;
            while(l >= 1){
                alice.push_back(r--);
                bob.push_back(l--);
            }
            l = N;
            while(r >= 1){
                alice.push_back(r--);
                bob.push_back(l--);
            }
        } else{
            int l = b;
            int r = N;
            while(l >= 1){
                alice.push_back(l--);
                bob.push_back(r--);
            }
            l = N;
            while(r >= 1){
                alice.push_back(l--);
                bob.push_back(r--);
            } 
        }
        cout << "YES" << '\n';
        for(int c:alice){
            cout << c << ' ';
        }
        cout << '\n';
        for(int c:bob){
            cout << c << ' ';
        }
        cout << '\n';
 
    }
    return 0;
}