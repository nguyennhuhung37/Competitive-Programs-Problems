#include<bits/stdc++.h>
using namespace std;
#define INF 1e9;
#define MAX 105
#define ii pair<int, int>

int T, n, m, res = 0;
vector<string> save;
vector<ii> graph[MAX];
int dist[MAX];

bool prim(int s){
    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, s});
    int cnt = 0;
    while(!pq.empty()){
        ii top = pq.top(); pq.pop();
        int w = top.first, u = top.second;
        if(dist[u] != w){
            continue;
        }
        res += dist[u]; cnt++;
        dist[u] = -INF;
        for(auto x : graph[u]){
            if(dist[x.first] > x.second){
                dist[x.first] = x.second;
                pq.push({dist[x.first], x.first});
            }
        }
    }
    if(cnt < n){
        return false;
    }
    return true;
}

int main(){
    cin >> T;
    for(int id = 1; id <= T; id++)
    {
        for(int i = 1; i < MAX;  i++) graph[i].clear();
        save.clear();
        cin >> m;
        for(int i = 1; i <= m; i++){
            string u, v; int w;
            cin >> u >> v >> w;
            if(find(save.begin(), save.end(), u) == save.end()){
                save.push_back(u);
            }
            int a = find(save.begin(), save.end(), u) - save.begin() + 1;
            if(find(save.begin(), save.end(), v) == save.end()){
                save.push_back(v);
            }
            int b = find(save.begin(), save.end(), v) - save.begin() + 1;
            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
        }
        n = save.size();
        res = 0;
        if(prim(1)) cout << "Case " << id << ": " << res << endl;
        else cout << "Case " << id << ": Impossible" << endl;
    }
    return 0;
}
