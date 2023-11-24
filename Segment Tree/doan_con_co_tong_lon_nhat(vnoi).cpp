#include<bits/stdc++.h>
using namespace std;
#define MAX 50000
#define ll long long

ll n, m, a[MAX+5];

struct node{
    ll s, Max, MaxL, MaxR;
};

node st[MAX*4];

node operator + (const node &a, const node &b){
    node res;
    res.s = a.s + b.s;
    res.Max = max({a.Max, b.Max, a.MaxR + b.MaxL});
    res.MaxL = max(a.MaxL, a.s + b.MaxL);
    res.MaxR = max(b.MaxR, a.MaxR + b.s);
    return res;
}

void build(int id, int l, int r){
    if(l == r){
        st[id] = {a[l], a[l], a[l], a[l]};
        return;
    }
    ll mid = (l+r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = st[id*2] + st[id*2+1];
}

node get(ll id, ll l, ll r, ll u, ll v){
    if(v < l || r < u){
        return {0, -INT_MAX, -INT_MAX, -INT_MAX};
    }
    if(u <= l && r <= v){
        return st[id];
    }
    ll mid = (l+r) / 2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cin >> m;
    while(m--){
        ll u, v; cin >> u >> v;
        cout << get(1, 1, n, u, v).Max << "\n";
    }
}
