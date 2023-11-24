#include<bits/stdc++.h>
using namespace std;
#define MAX 30000
#define ll long long

struct save{
    ll x, l, r, type;
};

bool operator < (const save &a, const save &b){
    return (a.x < b.x || (a.x == b.x && a.type < b.type));
}

struct node{
    ll cnt, len;
};

node st[MAX*4];
save a[MAX*2+5];
ll n, m = 0, k = 0;

void update(ll id, ll l, ll r, ll u, ll v, ll type){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        st[id].cnt += type;
        if(type == 1) st[id].len = r-l+1;
        else if(st[id].cnt == 0){
            if(l < r) st[id].len = st[id*2].len + st[id*2+1].len;
            else st[id].len = 0;
        }
        return;
    }
    int mid = (l+r) / 2;
    update(id*2, l, mid, u, v, type);
    update(id*2+1, mid+1, r, u, v, type);
    if(st[id].cnt == 0){
        st[id].len = st[id*2].len + st[id*2+1].len;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        k = max(k, y2);
        a[++m] = {x1, y1+1, y2, 1};
        a[++m] = {x2, y1+1, y2, -1};
    }
    sort(a+1, a+m+1);
    ll res = 0;
    for(int i = 1; i <= m; i++){
        res += st[1].len * (a[i].x - a[i-1].x);
        update(1, 1, k, a[i].l, a[i].r, a[i].type);
    }
    cout << res;
    return 0;
}
