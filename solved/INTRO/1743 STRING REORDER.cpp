/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
using namespace std;

//!!!EXPLANATION!!!:
/* 
The concept behind this is pretty simple, you just need to follow 2 rules, 
if the frequency of a char makes it that if you don't output it now then you will have no way of avoidig the same char twice in a row you output that immediatly.
If not, then you can just take the first charachter in alphabetical order that has a freq higher than zero.

This works because if you don't check at each iteration for the adjacent rule you will end up with two or more consecutive char because there are no 
other chars left.
Also, this works easily on chars because you have a time complexity of O(N*M) where M is the size of the alphabet you are using, ( in this case english alphabet
upper case only so M = 26) if you had a similar problem but instead of chars with numbers from 1 to 2e5 or even 1e9 that time complexity would be infeasible, but
you could reduce it to O(N logN) by using set, which i did not use in this case because it would have added a completely useless overhead to the algorithm.
Last thing, since the last char you put is always saved you can just check if in the ans string you left any space empty with a mark like '?', if so,
then the problem is impossible to solve. 
(You could even check this at the start by checking if any char frequency is strictly more than N/2)
*/

//Cases

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    string s;
    cin >> s;
    vector<int> freq(26,0);
    int N = s.size();
    for(int i = 0; i < N; i++){
        freq[s[i]-'A']++;
    }


    vector<char> ans(N,'?');
    bool possible = true;
    for(int i = 0; i < N && possible; i++){
        char previous = i-1 < 0 ? '?':ans[i-1];
        // just O(N*26) this time so go fuck yourself :)
        char here = '?';
        for(int j = 0; j < 26; j++){
            if(previous==('A'+j)) continue;
            if(freq[j] > 0 && freq[j] > (N-i)/2){
                here='A'+j;
                //cout << here << ' ' << i << '\n';
                break;
            }
            if(here == '?' && freq[j] > 0){
                here='A'+j;
            }
        }   
        if(here!='?')freq[here-'A']--;
        else possible=false;
        ans[i]=here;
    }

    if(possible){
        for(char a:ans){
        cout << a;
        }
    } else{
        cout << "-1";
    }
    cout << '\n';
    return 0;
}
