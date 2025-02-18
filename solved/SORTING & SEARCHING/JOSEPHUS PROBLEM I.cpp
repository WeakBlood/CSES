/* 
Sender:	WeakBlood
Submission time:	2025-02-18 23:15:07 +0200
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
For this problem we can just simulate what is asked so, first we skip one child, we remove one, we skip one, we remove one.
This process is made possible by using a deque ( double ended queue ) and flag for saying when you have to skip and when not.
This is more like a preparation for the next version of the josephus problem -_-.
Time complexity O(N) ?...
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
        bool skip = true;
        // base so one skips other no
        deque<int> q;
        for(int i = 1; i <= N; i++) q.push_back(i);
        
        while(!q.empty()){
            int child = q.front();
            q.pop_front();
            if(skip) q.push_back(child);
            else cout << child << ' ';
            skip=!skip;
        } 
        cout << '\n';
    }
    return 0;
}
