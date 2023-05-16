#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define iii pair<int, ii>
const int inf = 1e9;
vector<ii> adj[505];
int dist[505];
void Dijkstra(int s)
{
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    for(int i = 0; i < 501; i++) dist[i] = inf;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        ii tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        if (tmp.first > dist[u]) continue;
        for(auto x : adj[u]){
            int v = x.first;
            int c = x.second;
            if(dist[v] > dist[u] + c){
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
            }
        }
    }
}
void solve()
{
    int n; cin >> n;
    while(n--)
    {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    int s; cin >> s;
    Dijkstra(s);
    int q; cin >> q;
    while(q--)
    {
        int x; cin >> x;
        if(dist[x] == inf) cout << "NO PATH" << endl;
        else cout << dist[x] << endl;
    }
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
