#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
int t, n, m;
char a[25][25];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool la_bien(int i, int j)
{
    return (i == 1 || i == n || j == 1 || j == m);
}
bool check(int i, int j)
{
    return (i >= 1 && i <= n && j >= 1 && j <= m);
}
void bfs(int i, int j)
{
    queue<ii> q;
    q.push({i, j});
    a[i][j] = '#';
    while(!q.empty()){
        ii v = q.front();
        q.pop();
        for(int x = 0; x < 4; x++){
            ii tmp = {v.first + dx[x], v.second + dy[x]};
            if(check(tmp.first, tmp.second) && a[tmp.first][tmp.second] == '.'){
                a[tmp.first][tmp.second] = '#';
                q.push({tmp.first, tmp.second});
            }
        }
    }
}
void solve()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            if(la_bien(i, j) && a[i][j] == '.') cnt++;
        }
        if(cnt != 2){
            cout << "invalid" << endl; continue;
        }
        bool ok = false;
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(a[i][j] == '.' && la_bien(i, j) && !ok) {
                bfs(i, j);
                ok = true;
            }
            else if(a[i][j] == '.' && la_bien(i, j) && ok) ok = false;
        }
        if(ok) cout << "valid" << endl;
        else cout << "invalid" << endl;
    }
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
