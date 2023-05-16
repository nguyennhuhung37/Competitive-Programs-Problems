#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define iii pair<int, ii>
int n, m, k, cnt = 0;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
char s[55][55], copy_s[55][55];
bool la_ho = false;
vector<iii> v;
bool la_bien(int i, int j)
{
    return i == 1 || i == n || j == 1 || j == m;
}
bool check(int i, int j)
{
    return 1 <= i && i <= n && 1 <= j && j <= m;
}
void dfs(int i, int j)
{
    cnt++;
    s[i][j] = '*';
    if(la_bien(i, j)) la_ho = false;
    for(int x = 0; x < 4; x++){
        int a = i + dx[x], b = j + dy[x];
        if(check(a, b) && s[a][b] == '.'){
            dfs(a, b);
        }
    }
}
void solve()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        cin >> s[i][j];
        copy_s[i][j] = s[i][j];
    }
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        if(s[i][j] == '.'){
            cnt = 0; la_ho = true;
            dfs(i, j);
            if(la_ho) v.push_back({cnt, {i, j}});
        }
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < v.size() - k; i++) ans += v[i].first;
    cout << ans << endl;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        s[i][j] = copy_s[i][j];
    }
    for(int i = 0; i < v.size() - k; i++){
        int a = v[i].second.first, b = v[i].second.second;
        dfs(a, b);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << s[i][j];
        }
        cout << endl;
    }
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
