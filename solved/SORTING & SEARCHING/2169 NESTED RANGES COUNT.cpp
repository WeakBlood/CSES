/* 
Sender:	WeakBlood
Submission time:	2025-02-20 16:32:20 +0200
Language:	C++ (C++17)
Status:	READY
Result:	ACCEPTED
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
#define inf 1e9
using namespace __gnu_pbds;
using namespace std;
template<typename T> 
using mySet = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//!!!EXPLANATION!!!:
/* 
The problem asks us now to count the number of ranges we are inside and the number we contain not if we just 
are in one or none, so we are going to need a data structure which allows us to have quick insertions on sorteds sets, 
sounds familiar ? Yeah, we can use a "indexed-set" (this is the name i gave to it),  an indexed-set is just a set with additional
features, like "order_of_key" which returns the index of a certain value if we kept all the elements ordered, for example in the 
following indexed_set s = {2,3,5,6,9}; order_of_key(5) is 2 because 5 is at position 2, if we removed 3 we would have
s = {2,5,6,9} so now order_of_key(5) would return 1.
The indexed set is a really powerful data structure if we consider that all those operations are just in logₙ, 
so what are we going to do with this data structure? Just sort the ranges based on their end time, 
for each range you search the index of the first range  that has a an "A" value at least of A from the current range.
This works because if we have ranges = {1,6} {2,4} {4,8} {3,6} 
the rule here is a[1]<b[1] || (a[1]==b[1] && a[0]>=b[0]) so the one with a smaller end value goes first, but if they have the same value 
the one with bigger starting value goes first.
the sorted version would be {2,4} {3,6} {1,6} {4,8}
starting from the first there are no ranges before so nothing, we add the star of that range to the set which is 2, 
so now s = {2}
second, are there ranges with a start as big as 3? no, in fact lower_bound(3) returns s.end() so we just add 3 to the set, s = {2,3}
third, are there ranges with a start as big as 1?  YES, in fact lower_bound(1) is s.begin() (*s.begin() = 2), so the "order_of_key(2)"  will be 0, since 
2 is the first value of the set, and s.size()-0 is 2.
Since both 2 and 3 are bigger than 1,the range {1,6} contains two ranges. s = {1,2,3}
fourth, are there ranges with a start as big as 4? no, so we just add 4 to the set s = {1,2,3,4};
This means that only the range {1,6} contains two ranges.
The same process can be applied for counting how many ranges contains a single range, just invert everyterm i gave in the previous explanation.
Time complexity O(N logₙ)
*/


 
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
        vector<array<int,3>> ranges(N);
        for(int i  = 0; i < N; i++){
            cin >> ranges[i][0] >> ranges[i][1];
            //ranges[i][0]--; ranges[i][1]--;
            ranges[i][2]=i;
        }
        //sort(ranges.begin(),ranges.end());
        
        mySet<array<int,2>> s;
        sort(ranges.begin(),ranges.end(),[&](array<int,3> &a, array<int,3> &b){
            return a[1]<b[1] || (a[1]==b[1] && a[0]>=b[0]);
        });
        vector<int> contains(N,0);
        int justARef = 0;
        for(int i = 0; i < N; i++){
            auto it = s.lower_bound({ranges[i][0]});
            if(it != s.end()){
                contains[ranges[i][2]] = s.size()-s.order_of_key(*it);
                //cout << s.order_of_key(*it) << ' ' << *it << '\n';
            }
            s.insert({ranges[i][0],justARef++});
        }

        s.clear();
        justARef = 0;
        sort(ranges.begin(),ranges.end(),[&](array<int,3> &a, array<int,3> &b){
            return a[0]<b[0] || (a[0]==b[0] && a[1]>=b[1]);
        });
        vector<int> isContained(N,0);
        for(int i = 0; i < N; i++){
            auto it = s.lower_bound({ranges[i][1],0});
            //cout << ranges[i][0] << ' ' << ranges[i][1] << '\n';
            if(it != s.end()){
                isContained[ranges[i][2]] = s.size()-s.order_of_key(*it);
                //cout << s.order_of_key(*it) << '\n';
            }
            s.insert({ranges[i][1],justARef++});
        }
        // try to do the same in reverse because sometimse
        for(int u:contains){
            cout << u << ' ';
        }
        cout << '\n';
        for(int u:isContained){
            cout << u << ' ';
        }
 
    }
    return 0;
}