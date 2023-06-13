#include<bits/stdc++.h>
using namespace std;
#define MAX 30005

int parent[MAX], cnt[MAX], ranks[MAX];

int findSet(int u){
    if(parent[u] != u){
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

void unionSet(int u, int v){
    int up = findSet(u);
    int vp = findSet(v);
    if(up == vp){
        return;
    }
    else{
        parent[up] = parent[vp];
        cnt[vp] += cnt[up];
    }
}

void makeSet(){
    for(int i = 0; i < MAX; i++){
        parent[i] = i;
        ranks[i] = 0;
        cnt[i] = 1;
    }
}

int main(){
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        makeSet();
        for(int i = 1; i <= m; i++){
            int u, v; cin >> u >> v;
            unionSet(u, v);
        }
        int res = 0;
        for(int i = 1; i <= n; i++){
            res = max(res, cnt[i]);
        }
        cout << res << endl;
    }
    return 0;
}
