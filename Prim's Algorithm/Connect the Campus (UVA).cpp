#include<bits/stdc++.h>
using namespace std;
#define MAX_V 755
#define MAX_E 1005
#define INF 1e9

int n, m;

struct coordinates{
    double x, y;
};

coordinates a[MAX_V];
vector<pair<int, double> > graph[MAX_V];
double dist[MAX_V];

double prim(int s){
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>> > pq;
    dist[s] = 0;
    pq.push({0, s});
    double res = 0;
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        double w = top.first; int u = top.second;
        if(dist[u] != w){
            continue;
        }
        res += dist[u];
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
    while(cin >> n)
    {
        for(int i = 1; i <= n; i++) graph[i].clear();
        for(int i = 1; i <= n; i++){
            cin >> a[i].x >> a[i].y;
        }
        for(int i = 1; i <= n; i++) dist[i] = INF;

        cin >> m;
        map<pair<int, int>, bool> check;
        for(int i = 1; i <= m; i++){
            int u, v; cin >> u >> v;
            check[{u, v}] = true;
            check[{v, u}] = true;
            graph[u].push_back({v, 0});
            graph[v].push_back({u, 0});
        }
        for(int i = 1; i < n; i++){
            for(int j = i+1; j <= n; j++){
                if(check[{i, j}]) continue;
                double distance = sqrt(pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2));
                graph[i].push_back({j, distance});
                graph[j].push_back({i, distance});
            }
        }
        cout << setprecision(2) << fixed << prim(1) << endl;
    }
    return 0;
}
