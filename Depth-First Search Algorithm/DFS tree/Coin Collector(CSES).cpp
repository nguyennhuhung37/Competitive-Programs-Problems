#include<bits/stdc++.h>
using namespace std;
#define MAX 200000
#define ll long long
#define ii pair<ll, ll>

int n, m;
vector<int> a[MAX+5], b[MAX+5];
int timedfs = 0, scc = 0;
int num[MAX], low[MAX], tp[MAX], c[MAX];
ll f[MAX], res = 0, g[MAX];
stack<int> st;
bool vis[MAX];

void dfs(int u){
    num[u] = low[u] = ++timedfs;
    st.push(u);
    for(auto v : a[u]){
        if(!num[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else{
            low[u] = min(low[u], num[v]);
        }
    }
    if(low[u] == num[u]){
        ++scc;
        while(true){
            int top = st.top();
            st.pop();
            num[top] = low[top] = n+1;
            tp[top] = scc;
            f[scc] += (ll)c[top];
            if(top == u) break;
        }
    }
}

void sfd(int u){
    vis[u] = true;
    for(auto v : b[u]){
        if(!vis[u]){
            sfd(u);
        }
        g[u] = max(g[u], g[v]);
    }
    g[u] += f[u];
    res = max(res, g[u]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> c[i];
    while(m--){
        int u, v; cin >> u >> v;
        a[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) if(!num[i]) dfs(i);
    for(int u = 1; u <= n; u++) for(auto v : a[u]){
        if(tp[v] != tp[u]) b[tp[u]].push_back(tp[v]);
    }
    for(int i = 1; i <= scc; i++) if(!vis[i]) sfd(i);
    cout << res;
    return 0;
}
