#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define iii pair<int, ii>
int test = 1, n, m, ans = 0;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
string s[101];
bool visited[105][105];
bool ok = false;
bool check (int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}
void dfs(int i, int j, int tmp)
{
    for(int k = 0; k < 8; k++){
        int a = i + dx[k], b = j + dy[k];
        if(check(a, b) && s[a][b] == 'A' + tmp && !visited[a][b]){
            visited[a][b] = true;
            ans = max(ans, tmp + 1);
            dfs(a, b, tmp + 1);
            visited[a][b] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin >> n >> m)
    {
        if(!n && !m) break;
        ans = 0;
        for(int i = 0; i < n; i++) cin >> s[i];
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'A'){
                ans = max(1, ans);
                dfs(i, j, 1);
            }
        }
        cout << "Case " << test << ": " << ans << endl;
        test++;
    }
    return 0;
}
