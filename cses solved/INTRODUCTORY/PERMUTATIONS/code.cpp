#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif 

    int x;
    cin >> x;

    if(x == 1){ cout << 1 << endl;  return 0;}
    if(x < 4) { cout << "NO SOLUTION" << endl; return 0;}

    for(int i = 2; i <= x; i+=2) cout << i << " ";
    for(int i = 1; i <=x; i+=2) cout << i << " ";
    cout << endl;
    return 0;
}