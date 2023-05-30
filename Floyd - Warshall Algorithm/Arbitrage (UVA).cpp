#include <iostream>
using namespace std;
const int MAX = 40;

string currencies[MAX];
double dist[MAX][MAX];
int n, m;

int findCurrency(string s){
    for (int i = 0; i < n; i++)
        if (currencies[i] == s)
            return i;
    return -1;
}

void floydWarshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] < dist[i][k] * dist[k][j]) {
                    dist[i][j] = dist[i][k] * dist[k][j];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc = 1;
    string u, v;
    double w;

    while (true) {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = 0;
                if (i == j)
                    dist[i][j] = 1;
            }
        }
        for (int i = 0; i < n; i++)
            cin >> currencies[i];
        cin >> m;
        for (int i = 0; i < m; i++){
            cin >> u >> w >> v;
            dist[findCurrency(u)][findCurrency(v)] = w;
        }
        floydWarshall();
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (dist[i][i] > 1) {
                flag = true;
                break;
            }
        }
        cout << "Case " << tc++ << ": " << (flag ? "Yes" : "No") << "\n";
    }
    return 0;
}
