#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;

int parent[MAX];

int findSet(int u) {
    while (u != parent[u]) {
        u = parent[u];
    }
    return u;
}

void unionSet(int u, int v) {
    int up = findSet(u);
    int vp = findSet(v);
    parent[up] = vp;
}

int main() {
    int u, v, N, M;
    cin >> N >> M;

    if (N != M) {
        cout << "NO";
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        unionSet(u, v);
    }

    int nGroup = 0;
    for (int i = 1; i <= N; i++) {
        if (i == parent[i]) {
            nGroup++;
            if (nGroup > 1) {
                break;
            }
        }
    }

    cout << (nGroup == 1 ? "FHTAGN!" : "NO");
    return 0;
}
