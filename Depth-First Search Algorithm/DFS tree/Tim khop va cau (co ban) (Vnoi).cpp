#include<bits/stdc++.h>
using namespace std;
#define MAX_N 10005

int n, m;
vector<int> g[MAX_N];// danh sách cạnh kề của mỗi đỉnh
int timeDfs = 0, bridge = 0; // thời gian Dfs, số cạnh cầu;
int low[MAX_N], num[MAX_N];
//num[u] thứ tự duyệt Dfs của đỉnh u (thứ tự mà mỗi đỉnh bắt đầu duyệt)
//low[u] thứ tự thăm của đỉnh có thứ tự thăm sớm nhất nằm trong cây con gốc u hoặc kề cạnh với 1 đỉnh thuộc cây con gốc u
bool joint[MAX_N];//đánh dấu đỉnh khớp

void dfs(int u, int pre){
    int child = 0; // Số lượng con trực tiếp của đỉnh u trong cây DFS
    num[u] = low[u] = ++timeDfs;
    for (int v : g[u]) {
        if (v == pre) continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) bridge++;
            child++;
            if (u == pre) { // Nếu u là đỉnh gốc của cây DFS
                if (child > 1) joint[u] = true;
            }
            else if (low[v] >= num[u]) joint[u] = true;
        }
        else low[u] = min(low[u], num[v]);
    }
}

int main(){
    cin >> n >> m;
    while(m--){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!num[i]) dfs(i, i);
    }
    int cntJoin = 0;
    for(int i = 1; i <= n; i++) cntJoin += joint[i];
    cout << cntJoin << " " << bridge;
    return 0;
}
