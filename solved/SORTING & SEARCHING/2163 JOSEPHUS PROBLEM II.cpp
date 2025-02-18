/* 
Sender:	WeakBlood
Submission time:	2025-02-18 23:32:50 +0200
Language:	C++ (C++17)
Status:	READY
Result:	ACCEPTED
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long int
#define inf 1e9
using namespace std;

template<typename T> 
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

//!!!EXPLANATION!!!:
/* 
For this problem, we will need a really particular and useful data structure, the name that i gave to it
is "Indexed-Set" this is because by declaring all that stuff you have a normal set so istances of unique elements
with insertions and deletions in O(logₙ) BUT ALSO THE POSSIBILITY TO POINT AT THEM WITH AN INDEX BASED ON THE ORDER THEY WERE 
INSERTED, FOR EXAMPLE in this type of set if i insert 9,2,4 and i do "find_by_order(0)" i will get 9 as output, 
but the best part has yet to come, when i delete an element, THE INDEXES SHIFTS accordingly, and this is 
such a useful and good feature to have, because you don't have to store anything about indexes etc.
So even with a data structure that seems so complex, we still have thanks to this library
a Time complexity of O(N logₙ) (since each time we do find by order we take logₙ time)
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
        int N,K;
        cin >> N >> K;
        ordered_set<int> children;
        for(int i = 1; i <= N; i++) children.insert(i);
        int idx = 0; 
        while(!children.empty()){
            N = children.size();
            idx= (idx+K)%N;
            auto toRemove = children.find_by_order(idx);
            cout << *toRemove << ' ';
            children.erase(toRemove);
        }   
    }
    return 0;
}
