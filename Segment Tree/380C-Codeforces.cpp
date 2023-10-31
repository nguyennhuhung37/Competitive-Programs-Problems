#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005

string s;
int m, u, v;

struct Node {
    int optimal;
    int open;
    int close;
    Node(int op, int o, int c) {
        optimal = op;
        open = o;
        close = c;
    }
};

Node operator + (const Node& left, const Node& right){
    Node res(0, 0, 0);
    int tmp = min(left.open, right.close);
    res.optimal = left.optimal + right.optimal + tmp*2;
    res.open = left.open + right.open - tmp;
    res.close = left.close + right.close - tmp;
    return res;
}

vector<Node> st;

void build(int id, int l, int r){
    if(l == r){
        if(s[l] == '(') st[id] = Node(0, 1, 0);
        if(s[l] == ')') st[id] = Node(0, 0, 1);
        return;
    }
    int mid = (l+r) / 2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    st[id] = st[2*id] + st[2*id+1];
}

Node query(int id, int l, int r, int u, int v){
    if(v < l || r < u){
        return Node(0, 0, 0);
    }
    if(u <= l && r <= v){
        return st[id];
    }
    int mid = (l+r) / 2;
    return query(id*2, l, mid, u, v) + query(id*2+1, mid+1, r, u, v);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 0; i <= MAX * 4; i++)
    st.push_back(Node(0, 0, 0));
    cin >> s;
    int n = s.size();
    build(1, 0, n-1);
    cin >> m;
    while(m--){
        cin >> u >> v;
        cout << query(1, 0, n-1, u-1, v-1).optimal << "\n";
    }
    return 0;
}
