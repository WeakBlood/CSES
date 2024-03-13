#include <bits/stdc++.h>
// including standard libraries
using namespace std;
int main()
{
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int N;
    cin >> N;
    vector<int> v(N);
    v[0] = 0;
    for(int i = 1; i < N; i++)
    {
        cin >> v[i];
    }
 
    sort(v.begin(),v.end());
    for(int i = 0; i < N; i++)
    {
        if(v[i]!=i)
        {
            cout << i  << endl;
            break;
        }
    }
    if(v[N-1] != N) cout << N << endl;
    return 0;
}
