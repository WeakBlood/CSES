#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int main()
{
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif

    ll N,tot;
    cin >> N;

    ll arr[N];
    tot = 0;

    cin >> arr[0];
    for(ll i = 1; i < N; i++)
    {
        cin >> arr[i];
        if(arr[i] < arr[i-1])
        {
            tot+= (arr[i-1] - arr[i]);
            arr[i] += (arr[i-1] - arr[i]);
        }
    }
    cout << tot << endl;
    return 0;
}