#include <bits/stdc++.h>
#define MAX 100005
#define ii pair<int, int>
using namespace std;
using ll = long long;
const int inf = 1e9;

int n, m, k, x, A, B;
vector<ii> adj[MAX];
int city[MAX];// lưu k thành phố
int distA[MAX], distB[MAX];

void Dijkstra(int s, int dist[MAX])
{
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();
        int u = top.second;
        int d = top.first;
        if(dist[u] < d){
            continue;
        }
        for(auto x : adj[u]){
            if(dist[x.second] > x.first + d){
                dist[x.second] = x.first + d;
                pq.push({dist[x.second], x.second});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> x;
    for(int i = 1; i <= n; i++){
        distA[i] = inf;
        distB[i] = inf;
    }
    for(int i = 1; i <= k; i++) cin >> city[i];
    while(m--){
        int u, v, dis; cin >> u >> v >> dis;
        adj[u].push_back({dis, v});
        adj[v].push_back({dis, u});
    }
    cin >> A >> B;
    Dijkstra(A, distA);
    Dijkstra(B, distB);
    int ans = inf;
    for(int i = 1; i <= k; i++){
        if(distB[i] <= x){
            ans = min(ans, distA[i] + distB[i]);
        }
    }
    if(ans == inf) cout << -1;
    else cout << ans;
    return 0;
}
