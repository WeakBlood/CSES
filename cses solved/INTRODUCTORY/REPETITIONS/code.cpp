#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int mal = 1;
    int count = 1;
    for(size_t i = 1; i < s.size(); i++) // we use "size_t" just because we don't wanna get that annoying warning from the compiler. 
    {
        if(s[i-1] == s[i])
        {
            count++;
        }
        else
        {
            count = 1;
        }
        mal = max(mal,count);
    }
    cout << mal << endl;
    return 0;
}