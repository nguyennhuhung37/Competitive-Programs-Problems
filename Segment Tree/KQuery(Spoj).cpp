#include<bits/stdc++.h>
using namespace std;
#define MAX 30005
#define ii pair<int, int>

int n, a[MAX], q, id[MAX], ans[200005], st[4*MAX];
ii c[MAX];

struct Query{
    int k, l, r, t;
    bool operator < (const Query& other){
        return k < other.k;
    }
};

void build(int id, int l, int r){
    if(l == r){
        st[id] = 1;
        return;
    }
    int mid = (l+r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = st[id*2] + st[id*2+1];
}

void update(int id, int l, int r, int u){
    if(u < l || r < u){
        return;
    }
    if(l == r){
        st[id] = 0;
        return;
    }
    int mid = (l+r)/2;
    update(id*2, l, mid, u);
    update(id*2+1, mid+1, r, u);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id, int l, int r, int u, int v){
    if(v < l || r < u){
        return 0;
    }
    if(u <= l && r <= v){
        return st[id];
    }
    int mid = (l+r)/2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = {a[i], i};
    }
    sort(c + 1, c + n + 1);
    for(int i = 1; i <= n; i++) id[i] = c[i].second;
    vector<Query> queries;
    cin >> q;
    for(int i = 1; i <= q; i++){
        Query tmp;
        cin >> tmp.l >> tmp.r >> tmp.k;
        tmp.t = i;
        queries.push_back(tmp);
    }
    sort(queries.begin(), queries.end());
    build(1, 1, n);
    int i = 1;
    for(Query x : queries){
        while(i <= n && a[id[i]] <= x.k){
            update(1, 1, n, id[i]);
            i++;
        }
        ans[x.t] = get(1, 1, n, x.l, x.r);
    }
    for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
    return 0;
}
