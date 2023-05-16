#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define iii pair<int, ii>
int t, n, m;
vector<int> adj[10001];
int check[10001];
bool ok = false;
void dfs(int i)
{
    check[i] = 1;
    for(auto x : adj[i]){
        if(check[x] == 0) dfs(x);
        else if(check[x] == 1){
            ok = true; return;
        }
    }
    check[i] = 2;
}
void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        check[i] = 0;
        adj[i].clear();
    }
    while(m--)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    ok = false;
    for(int i = 1; i <= n; i++){
        if(check[i] == 0){
            dfs(i);
            if(ok){
                cout << "YES" << endl; return;
            }
        }
    }
    cout << "NO" << endl;
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
