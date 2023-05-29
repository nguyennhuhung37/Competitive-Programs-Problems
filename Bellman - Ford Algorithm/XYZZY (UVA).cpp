#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
#define MAX_V 105
#define MAX_E 105*104
#define ii pair<int, int>

int n, doors;
bool visited[MAX_V];
int dist[MAX_V], value[MAX_V];
vector<ii> graph;

bool hasPathBFS(int s, int f){
    fill(visited, visited + (n+1), false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto edge : graph){
            if(edge.first == u){
                int v = edge.second;
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                    if(v == f){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool BellmanFord(int s, int f){
    fill(dist, dist + (n+1), -INF);
    dist[1] = 100;
    for(int i = 0; i < n-1; i++){
        for(auto edge : graph){
            int u = edge.first;
            int v = edge.second;
            if(dist[u] > 0){
                dist[v] = max(dist[v], dist[u] + value[v]);
            }
        }
    }
    for(auto edge : graph){
        int u = edge.first;
        int v = edge.second;
        if(dist[u] > 0 && dist[u] + value[v] > dist[v] && hasPathBFS(u, f)){
            return true;
        }
    }
    return dist[f] > 0;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(cin >> n, n != -1)
    {
        graph.clear();
        for(int u = 1; u <= n; u++){
            cin >> value[u] >> doors;
            while(doors--){
                int v; cin >> v;
                graph.push_back({u, v});
            }
        }
        bool canGo = BellmanFord(1, n);
        cout << (canGo ? "winnable" : "hopeless") << endl;
    }
    return 0;
}

