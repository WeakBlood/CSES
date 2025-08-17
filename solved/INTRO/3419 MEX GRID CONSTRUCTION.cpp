/* 
@author WeakBlood<3
*/
#include <bits/stdc++.h>
 
#define ll long long int
#define inf 1e9
using namespace std;
 
//!!!EXPLANATION!!!:
/* 
 
*/
 
//Cases
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    #endif
    int N;
    cin >> N;   
 
    vector<set<int>> columnMex(N);
    for(int i = 0; i < N; i++){
        set<int> rowMex;
        
        for(int j = 0; j < N; j++){
            int rowMx = 0;
            while(rowMex.count(rowMx) || columnMex[j].count(rowMx)) rowMx++;
            cout << rowMx << ' ';
            rowMex.insert(rowMx);
            columnMex[j].insert(rowMx);
        }
        cout << '\n';
    }
    return 0;
}