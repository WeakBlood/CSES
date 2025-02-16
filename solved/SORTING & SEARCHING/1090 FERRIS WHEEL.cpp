/* 
Sender:	WeakBlood
Submission time:	2025-02-16 11:27:12 +0200
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
In this problem, which i tried to solve at midnight but without any progress because i was cooked, we need once again a multiset
because it can store multiple istances of the same element but still provides O(logₙ) insertions and deletions.
The key of this problem here, is understanding that the best child to pair with another will always be the child 
that gives you a summed weight as close as possible to K. 
We can achieve this by selecting the child on top of the set and searching for a child which weight is more than K-x where x = weightOfFirstChild
for this we can use "upper_bound(K-c)" which will point to the first element strictly greater than the target, if there is none then just .end() 
if the upper_bound is at the begging of the set, this means that there are NO children who can pair up with the first one because the would always exceed the K-x costraint.

Time complexity O(Nlogₙ);
*/

/*Take a set like s = {4,5,6,7,8,9} with upper_bound(10) we will point at s.end() this means that ALL ELEMENTS in the set are STRICTLY LESS than 10 which is correct
for upper_bound(3) the answer is s.begin(), because all elements of the set are STRICTLY GREATER than 3, so if i'm searching for someone who's weight is at MOST 6
i can just do prev(upper_bound(6)) because the upper_bound(6) will point at 7 ( because 7 > 6) and then i can go to the previous element with prev function.
For beign short, using this technique u are splitting the remaining weights into 2 parts, the left one being all the elements less than or equal to x and the right one 
being all the elements strictly greater than x. */

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
        multiset<int> children;
        for(int i = 0; i < N; i++){
            int a;
            cin >> a;
            children.insert(a);
        }

        int ans = 0;
        while(!children.empty()){
            int c = *children.begin();
            children.erase(children.begin());
            ans++;
            int otherC; // just a flag for verifying if the rule of not exceeding the total weight of K is being respected.
            if(children.empty()) otherC = inf;
            else {
                auto it = children.upper_bound(K-c);
                if(it == children.begin()) otherC = inf;
                else{
                    it--;
                    otherC = *it;
                    children.erase(it);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
