#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define ll long long
#define ii pair<int, int>

int n, m;
string s;

struct node{
    int s4, s7, s47, s74;
    bool lazy = 0;
};

node operator + (const node &a, const node &b){
    node res;
    res.s4 = a.s4 + b.s4;
    res.s7 = a.s7 + b.s7;
    res.s47 = max({a.s47 + b.s7, a.s4 + b.s47});
    res.s74 = max({a.s74 + b.s4, a.s7 + b.s74});
    return res;
}

node st[MAX*4];

void change(int id){
    swap(st[id].s4, st[id].s7);
    swap(st[id].s47, st[id].s74);
    st[id].lazy = 1 - st[id].lazy;
}

void build(int id, int l, int r){
    if(l == r){
        if(s[l] == '4') st[id] = {1, 0, 1, 1, 0};
        else st[id] = {0, 1, 1, 1, 0};
        return;
    }
    int mid = (l+r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id] = st[id*2] + st[id*2+1];
}

void update(int id, int l, int r, int u, int v){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        change(id);
        return;
    }
    int mid = (l+r) / 2;
    if(st[id].lazy){
        change(id*2);
        change(id*2+1);
        st[id].lazy = false;
    }
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    st[id] = st[id*2] + st[id*2+1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s;
    s = '0' + s;
    build(1, 1, n);
    while(m--){
        string type; cin >> type;
        if(type == "count"){
            cout << st[1].s47 << "\n";
        }
        else{
            int u, v; cin >> u >> v;
            update(1, 1, n, u, v);
        }
    }
    return 0;
}
