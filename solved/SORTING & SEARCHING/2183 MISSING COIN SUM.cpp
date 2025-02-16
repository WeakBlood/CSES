/* 
Sender:	WeakBlood
Submission time:	2025-02-16 19:09:17 +0200
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
This one is a bit tricky but still, for solving this the key is noticing that whenever a certain number is strictly greater than the sum off all of it's 
previous numbers + 1 it means that there is a gap, in possible sums, THAT ONE is the answer to our problem.
Don't believe me ? take v = {1,2,2,5,9}; the answer here is 20 why ? well,
We start with sum = 1
1 >= 1, 2 >= 2, 4 >= 2, 6>= 5, 11 >= 9, 20 >= NULL. The code ends.
1 was possible because there is one, 3 was possible cause 1+2, 8 was possible cause 5+2+1, etc.
But let's change the fourth number and make it 7, now we have v = {1,2,2,7,9};
1 >= 1, 2 >= 2, 4 >= 2, 6>=7... this is not true, so the code stops and answer is in fact, 6.
Time complexity O(N logₙ)
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
        priority_queue<ll,vector<ll>,greater<ll>> q;
        vector<int> v(N);
        for(int i = 0; i < N; i++){
            cin >> v[i];
        }
        
        sort(v.begin(),v.end());
        ll sums = 1;
        for(int i = 0; i < N && v[i] <= sums; i++){
            sums+=v[i];
        }
        cout << sums << '\n';
    }
    return 0;
}
