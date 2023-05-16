#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
int n, m, r1, c1, r2, c2;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char s[501][501];
bool ok = false;
bool check(int i, int j)
{
    return i >= 1 && i <= n && j >= 1 && j <= m;
}
void bfs()
{
    queue<ii> q;
    q.push({r1, c1});
    while(!q.empty()){
        ii v = q.front();
        q.pop();
        for(int x = 0; x < 4; x++){
            int a = v.first + dx[x], b = v.second + dy[x];
            if(a == r2 && b == c2 && s[a][b] == 'X'){
                ok = true; return;
            }
            if(check(a, b) && s[a][b] =='.'){
                s[a][b] = 'X';
                q.push({a, b});
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        cin >> s[i][j];
    }
    cin >> r1 >> c1 >> r2 >> c2;
    bfs();
    if(ok) cout << "YES";
    else cout << "NO";
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
