#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX 100005
#define ii pair<int, int>

int n, m, q;
vector<ii> graph[MAX];
int dist[MAX];
vector<int> save;

void prim(int s){
    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, s});
    while(!pq.empty()){
        ii top = pq.top(); pq.pop();
        int w = top.first, u = top.second;
        if(dist[u] != w){
            continue;
        }
        save.push_back(dist[u]);
        dist[u] = -INF;
        for(auto x : graph[u]){
            if(dist[x.first] > x.second){
                dist[x.first] = x.second;
                pq.push({dist[x.first], x.first});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    prim(1);
    cin >> q;
    for(int i = 1; i <= q; i++){
        int tmp; cin >> tmp;
        save.push_back(tmp);
    }
    sort(save.begin(), save.end());
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += (long long) save[i];
    }
    cout << ans;
    return 0;
}
