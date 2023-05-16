#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
ll st, en, n;
ll a[100001];
int dis[100001];
void bfs(ll st)
{
    queue<ll> q;
    q.push(st);
    dis[st] = 0;
    while(!q.empty()){
        ll v = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            ll tmp = v * a[i] % 100000;
            if(dis[tmp] == -1){
                 dis[tmp] = dis[v] + 1;
                 q.push(tmp);
            }
        }
    }
}
void solve()
{
    for(int i = 0; i < 100000; i++) dis[i] = -1;
    cin >> st >> en >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    bfs(st);
    cout << dis[en];
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
