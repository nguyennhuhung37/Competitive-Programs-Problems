#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
vector<int> adj[1001];
int dis[1001];
void dfs(int i)
{
    for(auto v : adj[i]){
        if(dis[v] == -1){
            dis[v] = dis[i] + 1;
            dfs(v);
        }
    }
}
void solve()
{
    int n; cin >> n;
    for(int i = 1; i < n; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        dis[i] = -1;
    }
    dis[1] = 0;
    dfs(1);
    ii ans = {1002, 1002};
    int q; cin >> q;
    while(q--)
    {
        int x; cin >> x;
        ans = min(ans, {dis[x], x});
    }
    cout << ans.second;
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
