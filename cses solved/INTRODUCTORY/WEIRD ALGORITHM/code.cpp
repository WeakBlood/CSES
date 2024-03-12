#include <iostream>
//we do not use bits/stdc++.h header because there is no need for any external libray
using namespace std;

void collatz(size_t x)
{
    //a simple reucursive approach that emulates the behaviours of the collatz conjecture
    cout << x << " ";
    if(x==1)
    {
        return;
    }
    if(x%2==0)
    {
        collatz(x/2);
    }
    else
    {
        collatz(x*3+1);
    }
}
int main()
{
    #ifdef LOCAL //ensuring that the input gets tested by file only in local 
    ifstream cin("input.txt"); 
    #endif
    size_t N;
    cin >> N;
    collatz(N);
    return 0;
}
