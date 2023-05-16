#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
int n, m;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool s[255][255];
bool check(int i, int j)
{
    return i >= 1 && i <= n && j >= 1 && j <= m;
}
int bfs(int i, int j)
{
    queue<ii> q;
    q.push({i, j});
    s[i][j] = 0;
    int cnt = 1;
    while(!q.empty()){
        ii v = q.front();
        q.pop();
        for(int x = 0; x < 4; x++){
            int a = v.first + dx[x], b = v.second + dy[x];
            if(check(a, b) && s[a][b]){
                cnt++;
                s[a][b] = 0;
                q.push({a, b});
            }
        }
    }
    return cnt;
}
void solve()
{
    while(cin >> n >> m)
    {
        if(!n) break;
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> s[i][j];
        }
        vector<int> ans;
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(s[i][j]) ans.push_back(bfs(i, j));
        }
        if(ans.empty()){
            cout << 0 << endl;
            continue;
        }
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        int dem = 1;
        for(int i = 0; i < ans.size()-1; i++){
            if(ans[i] < ans[i+1]) {
                cout << ans[i] << " " << dem << endl;
                dem = 1;
            }
            else dem++;
        }
        cout << ans[ans.size()-1] << " " << dem << endl;
    }
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
