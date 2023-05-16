#include <bits/stdc++.h>
#define MAX 10005
#define ii pair<int, int>
using namespace std;
const int INF = 1e9 + 7;

vector<ii> graphS[MAX], graphT[MAX];
int distS[MAX], distT[MAX];

void Dijkstra(int s, int dist[], vector<pair<int, int>> (&graph)[MAX]) {
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        ii top = pq.top();
        pq.pop();
        int u = top.second;
        int d = top.first;
        if(d > dist[u]) continue;
        for(auto x : graph[u]){
            if(dist[x.second] > d + x.first){
                dist[x.second] = d + x.first;
                pq.push({dist[x.second], x.second});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n, m, k, s, t, u, v, d;
    cin >> T;
    assert( T >= 1 && T <= 20);
    while (T--) {
        cin >> n >> m >> k >> s >> t;

        for (int i = 1; i <= n; i++) {
            graphS[i].clear();
            graphT[i].clear();
            distS[i] = INF;
            distT[i] = INF;
        }

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> d;

            graphS[u].push_back(make_pair(d, v));
            graphT[v].push_back(make_pair(d, u));
        }

        Dijkstra(s, distS, graphS);
        Dijkstra(t, distT, graphT);
        int res = distS[t];
        for (int i = 0; i < k; i++) {
            cin >> u >> v >> d;
            int a = distS[u] + d + distT[v];
            int b = distS[v] + d + distT[u];
            res = min(res, min(a, b));
        }

        cout << (res != INF ? res : -1) << endl;
    }
    return 0;
}
