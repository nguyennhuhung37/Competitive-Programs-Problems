#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>

int n, t, e;
vector<int> adj[100001];
bool visited[100001];

void dfs(int i)
{
    visited[i] = true;
    for(auto v : adj[i]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
    cin >> n >> e;
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < n; i++) adj[i].clear();
    for(int i = 1; i <= e ; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
    }
    return 0;
}
