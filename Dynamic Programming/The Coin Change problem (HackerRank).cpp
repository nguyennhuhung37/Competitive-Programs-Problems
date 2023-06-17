#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define fi first
#define se second
int n, m;
int c[52];
bool check[52][252];
ll ans[52][252];
ll solve(int i, int j)
{
    cout << i << " " << j << endl;
    if(j < 0) return 0;
    if(j == 0) return 1;
    if(i > m) return 0;
    if(check[i][j] == false){
        ans[i][j] = solve(i, j - c[i]) + solve(i+1, j);
        check[i][j] = true;
    }
    return ans[i][j];
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) cin >> c[i];
    cout << solve(1, n);
    return 0;
}
