#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
int n, m;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int soi = 0, cuu = 0, soi_song = 0, cuu_song = 0;
char s[255][255];
bool ok = false;
bool check(int i, int j)
{
    return i >= 1 && i <= n && j >= 1 && j <= m;
}
bool la_bien(int i, int j)
{
    return i == 1 || i == n || j == 1 || j == m;
}
void bfs(int i, int j)
{
    queue<ii> q;
    q.push({i, j});
    if(s[i][j] == 'k') cuu++;
    else if(s[i][j] == 'v') soi++;
    s[i][j] = '#';
    while(!q.empty()){
        ii v = q.front();
        q.pop();
        for(int x = 0; x < 4; x++){
            int a = v.first + dx[x], b = v.second + dy[x];
            if(check(a, b) && s[a][b] != '#'){
                if(s[a][b] == 'k') cuu++;
                else if(s[a][b] == 'v') soi++;
                s[a][b] = '#';
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
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        if(s[i][j] != '#' && la_bien(i, j)){
            cuu = 0; soi = 0;
            bfs(i, j);
            cuu_song += cuu;
            soi_song += soi;
        }
    }
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        if(s[i][j] != '#'){
            cuu = 0; soi = 0;
            bfs(i, j);
            if(cuu > soi) cuu_song += cuu;
            else soi_song += soi;
        }
    }
    cout << cuu_song << " " << soi_song;
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
