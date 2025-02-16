/* 
Sender:	WeakBlood
Submission time:	2025-02-16 19:27:49 +0200
Language:	C++ (C++17)
Status:	READY
Result:	ACCEPTED
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
using namespace std;

//!!!EXPLANATION!!!:
/* 
In this problem we can use a normal vector since N <= 2*10⁵ for tracking each number, now, 
we can take multiple numbers in a single round only if appear in some increasing order, like for example 
v = {5,3,2,4,1} this is a bad scenario, but in a single round we can take 3 and 4 because 3 comes before 4 
so the total of rounds will be 4 rounds.
If we had a perfectly sorted vector in increasing order we would need only 1 round no matter how big N is.
Time complexity O(N)
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
        int N;
        cin >> N;
        vector<int> appears(N+1,-1);
        int round = 0;
        for(int i = 0; i < N; i++){
            int a;
            cin >> a;
            if(a == 1){
                appears[a]=round++;
            } else{
                if(appears[a-1]==-1) appears[a]=round++;
                else appears[a]=appears[a-1];
            }
        }
        cout << round << '\n';
    }
    return 0;
}
