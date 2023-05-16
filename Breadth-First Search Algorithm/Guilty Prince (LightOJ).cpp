#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
int t, n, m, cnt = 0;
char s[25][25];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool check(int i, int j)
{
    return 1 <= i && i <= n && 1 <= j && j <= m;
}
int bfs(int i, int j)
{
    queue<ii> q;
    q.push({i, j});
    cnt = 1;
    s[i][j] = '#';
    while(!q.empty()){
        ii v = q.front();
        q.pop();
        for(int x = 0; x < 4; x++){
            int a = v.first + dx[x], b = v.second + dy[x];
            if(check(a, b) && s[a][b] == '.'){
                cnt++;
                s[a][b] = '#';
                q.push({a, b});
            }
        }
    }
    return cnt;
}
void solve()
{
    cin >> t;
    for(int id = 1; id <= t; id++)
    {
        cin >> m >> n;
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> s[i][j];
        }
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(s[i][j] == '@') cout << "Case " << id << ": " << bfs(i, j) << endl;
        }
    }
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
