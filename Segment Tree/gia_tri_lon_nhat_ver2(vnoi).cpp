#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 50000
#define ii pair<int, int>

struct Node{
    int lazy, value;
};

vector<Node> st(MAX*4, {0,0});

void down(int id){
    int t = st[id].lazy;
    st[id*2].lazy += t;
    st[id*2].value += t;
    st[id*2+1].lazy += t;
    st[id*2+1].value += t;
    st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int k){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        st[id].lazy += k;
        st[id].value += k;
        return;
    }
    int mid = (l+r) / 2;
    down(id);
    update(id*2, l, mid, u, v, k);
    update(id*2+1, mid+1, r, u, v, k);
    st[id].value = max(st[id*2].value, st[id*2+1].value);
}

int get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return st[id].value;
    int mid = (l+r) / 2;
    down(id);
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int n, m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    while(m--){
        int type; cin >> type;
        if(type == 0){
            int u, v, k; cin >> u >> v >> k;
            update(1, 1, n, u, v, k);
        }
        else{
            int u, v; cin >> u >> v;
            cout << get(1, 1, n, u, v) << "\n";
        }
    }
    return 0;
}
