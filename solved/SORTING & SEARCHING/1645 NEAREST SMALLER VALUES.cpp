/* 
Sender:	WeakBlood
Submission time:	2025-02-23 13:28:18 +0200
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
For this we will be using a min stack which is well documented here: https://cp-algorithms.com/data_structures/stack_queue_modification.html
Time complexity O(N)
*/

//Cases

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    stack<array<int,2>> s;
    int N;
    cin >> N;
    int a;
    cin >> a;
    s.push({a,1});
    cout << 0 << ' ';
    for(int i = 2; i <= N; i++){
        cin >> a;
        while(!s.empty() && s.top()[0] >= a)s.pop();
        if(!s.empty()) cout << s.top()[1] << ' ';
        else cout << 0 << ' ';
        s.push({a,i});
    }
    return 0;
}
