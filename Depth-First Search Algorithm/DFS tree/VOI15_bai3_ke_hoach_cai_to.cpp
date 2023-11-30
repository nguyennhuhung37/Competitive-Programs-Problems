#include<bits/stdc++.h>
using namespace std;
#define MAX 200000
#define ll long long
#define ii pair<ll, ll>

ll n, m;
ll timedfs = 0, cnt = 0, bridge = 0;
vector<ll> g[MAX+5], save;
ll num[MAX+5], low[MAX+5], tail[MAX+5];
vector<ii> t;

void dfs(ll u, ll pre){
    num[u] = low[u] = ++timedfs;
    cnt++;
    for(auto v : g[u]){
        if(v == pre) continue;
        if(!num[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] == num[v]) {
                bridge++;
                t.push_back({u, v});
            }
        }
        else{
            low[u] = min(low[u], num[v]);
        }
    }
    tail[u] = timedfs;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= m; i++){
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(ll i = 1; i <= n; i++){
        if(!num[i]){
            cnt = 0;
            dfs(i, i);
            save.push_back(cnt);
        }
    }
    if(save.size() >= 3) cout << 0;
    else if(save.size() == 2){
        cout << (m - bridge) * save[1] * save[0];
    }
    else{
        ll res = (m-bridge) * (n * (n-1) / 2 - m);
        for(auto x : t){
            ll v = x.second;
            ll tmp = tail[v] - num[v] + 1;
            res += tmp * (n - tmp) - 1;
        }
        cout << res;
    }
    return 0;
}
