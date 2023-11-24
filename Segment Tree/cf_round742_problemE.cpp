#include<bits/stdc++.h>
using namespace std;
#define MAX 200000
#define ll long long

int n, q, a[MAX+5];

struct node{
    ll s, l, r, dau, cuoi, do_lon;
};

node operator + (const node &a, const node &b){
    if(a.s == 0) return b;
    if(b.s == 0) return a;
    node res;
    res.dau = a.dau;
    res.cuoi = b.cuoi;
    res.do_lon = a.do_lon + b.do_lon;
    if(a.cuoi <= b.dau){
        if(a.l == a.do_lon) res.l = a.l + b.l;
        if(b.r == b.do_lon) res.r = a.r + b.r;
        res.s = a.s + b.s + a.r * b.l;
    }
    else{
        res.l = a.l;
        res.r = b.r;
        res.s = a.s + b.s;
    }
    return res;
}

node st[MAX*4];

void build(int id, int l, int r){
    if(l == r){
        st[id] = {1, 1, 1, a[l], a[l], 1};
        return;
    }
    ll mid = (l+r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = st[id*2] + st[id*2+1];
}

void update(int id, int l, int r, ll x, ll y){
    if(x < l || r < x) return;
    if(l == r){
        st[id] = {1, 1, 1, y, y, 1};
        return;
    }
    ll mid = (l+r) / 2;
    update(id*2, l, mid, x, y);
    update(id*2+1, mid+1, r, x, y);
    st[id] = st[id*2] + st[id*2+1];
}

node get(int id, int l, int r, int u, int v){
    if(v < l || r < u){
        return {0, 0, 0, 0, 0, 0};
    }
    if(u <= l && r <= v){
        return st[id];
    }
    int mid = (l+r) / 2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(q--){
        int type; cin >> type;
        if(type == 1){
            ll x, y; cin >> x >> y;
            update(1, 1, n, x, y);
        }
        else{
            int u, v; cin >> u >> v;
            cout << get(1, 1, n, u, v).s << "\n";
        }
    }
    return 0;
}
