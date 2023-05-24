#include <bits/stdc++.h>
#define MAX_V 1005
#define MAX_E 2005
using namespace std;
const int INF = 1e9 + 7;

struct Edge{
    int source, target, weight;
};
int t, n, m;
Edge graph[2005];
int dist[1005];
bool BellmanFord(int s){
    for(int i = 0; i < n; i++) dist[i] = INF;
    dist[s] = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            int u = graph[j].source;
            int v = graph[j].target;
            int w = graph[j].weight;

            if(dist[u] != INF  && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int i = 0; i < m; i++){
        int u = graph[i].source;
        int v = graph[i].target;
        int w = graph[i].weight;
        if(dist[u] != INF && dist[u] + w < dist[v]){
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int x, y, z; cin >> x >> y >> z;
            graph[i] = (Edge) {x, y, z};
        }
        cout << (!BellmanFord(0) ? "possible" : "not possible") << endl;
    }
}
