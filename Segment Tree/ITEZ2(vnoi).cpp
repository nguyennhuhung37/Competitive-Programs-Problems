#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 200005
#define ii pair<int, int>

ll n, q, a[MAX] = {0};
ll st[MAX*4];

void build(ll id, ll l, ll r){
    if(l == r){
        st[id] = a[l];
        return;
    }
    ll mid = (l+r) >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = st[id*2] + st[id*2+1];
}

void update(ll id, ll l, ll r, ll u, ll val){
    if(u < l || r < u) return;
    if(l == r){
        a[u] = val;
        st[id] = a[u];
        return;
    }
    ll mid = (l+r) >> 1;
    update(id*2, l, mid, u, val);
    update(id*2+1, mid+1, r, u, val);
    st[id] = st[id*2] + st[id*2+1];
}

ll get(ll id, ll l, ll r, ll u, ll v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    ll mid = (l+r) >> 1;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    build(1, 1, n);
    cin >> q;
    while(q--){
        ll type; cin >> type;
        if(type == 1){
            ll u, val; cin >> u >> val;
            update(1, 1, n, u, val);
        }
        else{
            ll u, v; cin >> u >> v;
            cout << get(1, 1, n, u, v) << "\n";
        }
    }
    return 0;
}
