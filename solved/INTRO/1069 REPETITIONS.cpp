/*
Sender:	WeakBlood
Submission time:	2025-02-11 18:03:28 +0200
Language:	C++ (C++17)
Status:	READY
Result:	ACCEPTED
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int T = 1;
    while(T--){
        string s;
        cin >> s;
        int l = 1;
        int maxi = 1;
        char ref = '$';
        for(char c:s){
            maxi = max(maxi,l);
            if(c == ref){
                l++;
            } else{
                l = 1;
                ref = c;
            }
        }
        maxi = max(maxi,l);
        cout << maxi << '\n';
    }
    return 0;
}
