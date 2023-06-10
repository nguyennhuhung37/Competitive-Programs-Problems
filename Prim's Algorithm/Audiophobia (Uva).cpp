#include<bits/stdc++.h>
using namespace std;
#define MAX 105
#define INF 1e9
#define ii pair<int, int>

int c, s, q, res;
vector<ii> graph[MAX];
vector<int> mstgraph[MAX];
int path[MAX];
bool visited[MAX];
int dist[MAX];
int save[MAX][MAX];

void prim(int s){
    for(int i = 1; i <= c; i++) dist[i] = INF;
    dist[s] = 0; path[s] = s;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push({0, s});
    while(!pq.empty()){
        ii top = pq.top(); pq.pop();
        int w = top.first, u = top.second;
        if(dist[u] != w){
            continue;
        }
        visited[u] = true;
        dist[u] = -INF;
        if(path[u] != -1 && path[u] != u){
            mstgraph[u].push_back(path[u]);
            mstgraph[path[u]].push_back(u);
        }
        for(auto x : graph[u]){
            if(dist[x.first] > x.second){
                dist[x.first] = x.second;
                path[x.first] = u;
                pq.push({dist[x.first], x.first});
            }
        }
    }
}

bool dfs(int c1, int c2){
    for(int i = 1; i <= c; i++) visited[i] = false;
    path[c1] = c1;
    visited[c1] = true;
    queue<int> q;
    q.push(c1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto x : mstgraph[u]){
            if(x == c2){
                path[c2] = u;
                int tmp = c2;
                while(tmp != path[tmp]){
                    res = max(res, save[tmp][path[tmp]]);
                    tmp = path[tmp];
                }
                return true;
            }
            if(!visited[x]){
                visited[x] = true;
                path[x] = u;
                q.push(x);
            }
        }
    }
    return false;
}

int main(){
    int id = 0;
    while(cin >> c >> s >> q){
        id++;
        if(c == 0) break;
        for(int i = 1; i <= c; i++){
            graph[i].clear();
            mstgraph[i].clear();
        }
        for(int i = 1; i <= s; i++){
            int c1, c2, d; cin >> c1 >> c2 >> d;
            graph[c1].push_back({c2, d});
            graph[c2].push_back({c1, d});
            save[c1][c2] = d;
            save[c2][c1] = d;
        }
        for(int i = 1; i <= c; i++){
            path[i] = -1;
            visited[i] = false;
        }
        for(int i = 1; i <= c; i++){
            if(!visited[i]){
                prim(i);
            }
        }
        cout << "Case #" << id << endl;
        while(q--){
            int c1, c2; cin >> c1 >> c2;
            res = -1;
            if(dfs(c1, c2)){
                cout << res << endl;
            }
            else cout << "no path" << endl;
        }
        cout << endl;
    }
    return 0;
}
