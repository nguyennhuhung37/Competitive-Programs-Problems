#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MAX_V 10005
#define MAX_E 100005
#define ii pair<int, int>

int n, m;
int dist[MAX_V];
vector<ii> graph[MAX_V];

long long prim(int s){
    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[s] = 0;
    long long res = 0ll;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, s});
    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();
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
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    cout << prim(1);
    return 0;
}
