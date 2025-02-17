/* 
Sender:	WeakBlood
Submission time:	2025-02-17 23:31:22 +0200
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
For this problem, we will simulate the problem by manually adding each traffic light and changing the lens as consequence,
but what can we notice? Do we actually need to change every single interval after we add only one traffic light? 
No, we just need to change the one traffic light after our new one and the one before, by doing this we will reduce
the number of operations drastically by just searching with a lower_bound the first value that is greater 
than our new traffic light. 
For being more explicit if we have intervals from {0,5} {7,9} {10,30} the lens will be {5,2,2,1,20}; 
so if we add a new traffic light at position 20 what happens? only the interval {10,30} gets split into two parts.
So after the operation we will have {0,5} {7,9} {10,20} {30}; so the new lens will be {5,2,2,1,10,10}; as you can see, only 
the 2 numbers withing the range of added traffic light needed an updated.

Time complexity: O(N logₙ)
*/

//Something that will be really useful is considering 0 and K as natively placed traffic lights and adding K to the lens multiset. 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int T;
    T = 1;
    while(T--){
        int K,Q;
        cin >> K >> Q;
        set<int> s = {0,K}; // this is because there are already two "stops" 0 and K 
        multiset<int> lens{K};  // there could be multiple lens of the same size 

        while(Q--){
            int a;
            cin >> a;
            auto r = s.lower_bound(a);
            // we remove the len that is between it and prev it 
            auto l = prev(r);
            lens.erase(lens.find(*r-*l)); // removing the len of before AND LET'S ALL REMEMBER THAT FOR REMOVING ONLY ONE ISTANCE OF AN ELEMENT FROM A MULTISET WE NEED TO DO FIND FIRST :)
            lens.insert(a-*l); // adding a new len from l to a 
            lens.insert(*r-a); // same thing with r 
            s.insert(a); // inserting new traffic light
            cout << *prev(lens.end()) << ' ';
        }

    }
    return 0;
}
