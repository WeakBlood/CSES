/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>

#define ll long long int
#define inf 1e9
using namespace std;

//!!!EXPLANATION!!!:
/* 
For solving this problem, we need to understand how do palindromes work in the first place,
if the lenght of the string is even, this means that we need all charachters to appear an even number of times, no exclusions.
else if the lenght of the string is odd we still need all charachters to appear an even number times PLUS only one charachter that appears an odd number of times.
This works because if you want a string of even lenght to be palindrome you will never have a charachter appearing x times where x is odd.
For printing out the palindromed ( new term invented XD ) string, you can use pretty much everything, from a set to a vector, you just need to output on both ends the same charachter 
for the number of times it appears in the string with the special case for odd string in which you output that char in the excact middle of the string.

Time Complexity O(N) with vector of frequency  O(Nlogₙ) in case you wanna use a map.
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
    int N = 26;
    vector<int> freq(N,0);

    for(char c:s){
        freq[c-'A']++;
    }
    int n = s.size();
    bool possible = true;
    bool odd = false;
    queue<pair<char,int>> q;
    for(int i = 0; i < N; i++){
        if(freq[i]&1){
            if(n&1 && !odd) odd = true;
            else possible = false;
        } 
        if(freq[i] != 0) q.push({'A'+i,freq[i]});
    }
    if(n&1 && !odd) possible = false;
    if(!possible){
        cout << "NO SOLUTION" << '\n';
        return 0;
    }
    int l = 0, r = n-1;
    while(!q.empty()){
        auto[c,f] = q.front();
        q.pop();
        if(f == 1 && l == r){
            s[l]=c;
        } else if(f > 1){
            s[l++]=c;
            s[r--]=c;
            if(f > 2) q.push({c,f-2});
        } else{
            q.push({c,f});
        }
    }

    cout << s << '\n';
    return 0;
}
