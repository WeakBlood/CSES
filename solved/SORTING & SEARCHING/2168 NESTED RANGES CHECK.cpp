/* 
Sender:	WeakBlood
Submission time:	2025-02-20 14:51:34 +0200
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
This problem can be resolved by sorting the ranges in a specific way,for finding 
IF some ranges contain completely others and viceversa, 
First, for finding if a range is contained in another we can sort 
the ranges with this rule  = "a[0]<b[0] || (a[0]==b[0] && a[1]>=b[1])"
this means that if the range with the smaller starts goes first, but if 
the starts are equal THE ONE WITH THE BIGGER END GOES FIRST, but why is that? 
Consider ranges {1,6} {1,3} {4,8} {3,6} if we sort them directly without 
this particular rule we will have {1,3} {1,6} {3,6} {4,8}
since each range checks all the ends of the ranges before we will have 
that {1,3} is NOT contained in any range since is the first one, but this is NOT true, instead, if
we sort them with that rule we will have {1,6} {1,3} {3,6} {4,8}
now starting from 1,6 is it contained in some other range? no, why ? because no other ranges have a smaller start value that it.
Going to 1,3 is it contained in some other range? Yes, because there are other ranges that have a smaller or equal start value AND 
the biggest END value (maxEnd = 6 because of one {1,6}) of a range is GREATER than the end value of this range.
What about 3,6 is it contained in some other range? Yes, for the same reason, since maxEnd = 6 and the end of this range is 6 we are still 
in the range {1,6}.
Going to the final one, even if we have 3 ranges before, THE MAX END VALUE OF THOSE RANGES IS NOT GREATER OR EQUAL to 8 WHICH IS THE 
END VALUE OF THIS RANGE, THIS MEANS, THAT NO RANGES IN THE ARRAY CONTAIN the range {4,8}

This explanation works the same if we swap all terms, so we sort them based on end values and then check for max start value when 
we want to check if a certain range contains other.

Time complexity O(N logₙ)
*/
 
//It is important to say that with this approach WE CANNOT solve the problem in one iteration only since only THE BIGGEST range is being tracked.

 
 

 
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
            ranges[i][0]--; ranges[i][1]--;
            ranges[i][2]=i;
        }
        //sort(ranges.begin(),ranges.end());
        
        sort(ranges.begin(),ranges.end(),[&](array<int,3> &a, array<int,3> &b){
            return a[0]<b[0] || (a[0]==b[0] && a[1]>=b[1]);
        });

        int idMax = -1;
        vector<bool> isContained(N,false);
        for(int i = 0; i < N; i++){
            if(idMax != -1){
                if(ranges[idMax][1]>=ranges[i][1]){
                    isContained[ranges[i][2]]=true;
                    //contains[ranges[idMax][2]]=true;
                }
            }
            if(idMax == -1 || (ranges[idMax][1] < ranges[i][1])) idMax = i;
        }
        sort(ranges.begin(),ranges.end(),[&](array<int,3> &a, array<int,3> &b){
            return a[1]<b[1] || (a[1]==b[1] && a[0]>=b[0]);
        });
        
        vector<bool> contains(N,false);
        idMax = -1;
        for(int i = 0; i < N; i++){
            if(idMax != -1){
                if(ranges[idMax][0]>=ranges[i][0]){
                    contains[ranges[i][2]]=true;
                    //contains[ranges[idMax][2]]=true;
                }
            }
            if(idMax == -1 || (ranges[idMax][0] < ranges[i][0])) idMax = i;
        }
        // try to do the same in reverse because sometimse
        for(bool u:contains){
            cout << u << ' ';
        }
        cout << '\n';
        for(bool u:isContained){
            cout << u << ' ';
        }
 
    }
    return 0;
}