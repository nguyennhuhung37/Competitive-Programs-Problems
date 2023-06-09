#include<bits/stdc++.h>
using namespace std;
#define INF 1e9;
#define MAX 1005
#define ii pair<int, int>

int t, p, n, m;
vector<ii> graph[MAX];
int dist[MAX];

long long prim(int s){
    for(int i = 1; i <= n; i++) dist[i] = INF;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    dist[s] = 0;
    pq.push({0, s});
    long long res = 0;
    while(!pq.empty()){
        auto top = pq.top(); pq.pop();
        int w = top.first, u = top.second;
        if(dist[u] != w){
            continue;
        }
        res += (long long) dist[u];
        dist[u] = -INF;
        for(auto x : graph[u]){
            if(dist[x.first] > x.second){
                dist[x.first] = x.second;
                pq.push({dist[x.first], x.first});
            }
        }
    }
    return res;
}
int main(){
    cin >> t;
    while(t--)
    {
        cin >> p >> n >> m;
        for(int i = 1; i <= n; i++) graph[i].clear();
        for(int i = 1; i <= m; i++){
            int u, v, w; cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        cout << prim(1) * (long long) p << endl;
    }
    return 0;
}
