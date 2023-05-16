#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int q;
vector<int> adj[1001];
int dis[1001];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto x : adj[v]){
            if(dis[x] == -1){
                dis[x] = dis[v] + 1;
                q.push(x);
            }
        }
    }
}
void solve()
{
    cin >> q;
    while(q--)
    {
        int n, m; cin >> n >> m;
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            dis[i] = -1;
        }
        while(m--)
        {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int s; cin >> s;
        bfs(s);
        for(int i = 1; i <= n; i++){
            if(i == s) continue;
            if(dis[i] == -1) cout << "-1 ";
            else cout << dis[i] * 6 << " ";
        }
        cout << endl;
    }
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
