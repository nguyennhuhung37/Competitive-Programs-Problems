#include <bits/stdc++.h>
#define MAX 105
#define ii pair<int, int>
using namespace std;
using ll = long long;
int T, n, m, s, d;
vector<int> adj[MAX];
int bfs(int s, int t)
{
    int dist[MAX];
    for(int i = 0; i < n; i++) dist[i] = -1;
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v == t){
            return dist[t];
        }
        for(auto x : adj[v]){
            if(dist[x] == -1){
                dist[x] = dist[v] + 1;
                q.push(x);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    for(int i = 1; i <= T; i++)
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            adj[i].clear();
        }
        while(m--)
        {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        cin >> s >> d;
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, bfs(s, i) + bfs(i, d));
        }
        cout << "Case "<< i << ": " << ans << endl;
    }
    return 0;
}
