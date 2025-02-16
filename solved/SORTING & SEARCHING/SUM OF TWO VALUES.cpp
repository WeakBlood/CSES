/* 
Sender:	WeakBlood
Submission time:	2025-02-16 13:08:13 +0200
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
For this problem we will use a map in combination of a vector since the value we want to find is fixed, each time before adding a number to the map we check if 
there is already in the map a value equal to X-a and in that case we output the two indexes other wise, we just add the index to the map, we can even simplify it 
more by removing vector since it is a bit useless in the Two values version XD.
Time complexity: O(N logₙ)

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
        int N,X;
        cin >> N >> X;
        map<int,vector<int>> values;
        bool found = false;
        for(int i = 0; i < N && !found; i++){
            int a;
            cin >> a;
            if(values.find(X-a) != values.end()){
                cout << i+1 << ' ' << values[X-a].back() << '\n';
                found = true;
            }
            values[a].push_back(i+1);
        }

        if(!found) cout << "IMPOSSIBLE" << '\n';

    }
    return 0;
}
