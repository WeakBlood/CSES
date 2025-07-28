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
    vector<bool> nums(N+1,false);
    for(int i = 0; i < N-1; i++){
        int a;
        cin >> a;
        nums[a]=true;
    }
    for(int i = 1; i <= N; i++){
        if(!nums[i]) {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}