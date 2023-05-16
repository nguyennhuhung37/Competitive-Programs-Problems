#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define iii pair<int, ii>
int t, n, m;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
string s[101];
string key = "ALLIZZWELL";
bool visited[105][105];
bool ok = false;
bool check (int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}
void dfs(int i, int j, int cnt)
{
    if(cnt == key.size()){
        ok = true;
        return;
    }
    for(int k = 0; k < 8; k++){
        int a = i + dx[k], b = j + dy[k];
        if(check(a, b) && s[a][b] == key[cnt] && !visited[a][b]){
            visited[a][b] = true;
            dfs(a, b, cnt + 1);
            visited[a][b] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        ok = false;
        for(int i = 0; i < n; i++) cin >> s[i];
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'A' && !ok){
                dfs(i, j, 1);
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
