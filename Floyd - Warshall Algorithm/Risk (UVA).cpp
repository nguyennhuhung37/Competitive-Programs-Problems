#include <bits/stdc++.h>
#define N 20
using namespace std;
const int INF = 1e9 + 7;

int dist[N + 1][N + 1];

string formatted(int n) {
    return (n >= 10 ? to_string(n) : " " + to_string(n));
}

void FloydWarshall() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int X, Q, u, v, j, t = 1;

    while (true) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = INF;
            }
        }

        for (int i = 1; i < N; i++) {
            if (!(cin >> X)) {
                return 0;
            }

            while (X--) {
                cin >> j;
                dist[i][j] = dist[j][i] = 1;
            }
        }

        FloydWarshall();

        cout << "Test Set #" << t++ << endl;

        cin >> Q;
        for (int i = 0; i < Q; i++) {
            cin >> u >> v;
            cout << formatted(u) << " to " << formatted(v) << ": " << dist[u][v] << endl;
        }
        cout << endl;
    }
    return 0;
}
