#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define iii pair<int, ii>
int t, dinh1;
vector<ii> adj[50001];
bool visited[50001];
ll dis[50001];
ii tmp = {0, 0};
void dfs(int i)
{
    memset(visited, false, sizeof(visited));
    memset(dis, 0, sizeof(dis));
    tmp = {0, 0};
    visited[i] = true;
    stack<int> st;
    st.push(i);
    while(!st.empty()){
        int v = st.top();
        st.pop();
        for(auto x : adj[v]){
            int a = x.first, distance = x.second;
            if(!visited[a]){
                dis[a] = dis[v] + distance;
                tmp = max(tmp, {dis[a], a});
                visited[a] = true;
                st.push(a);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        for(int i = 1; i <= n; i++) adj[i].clear();
        for(int i = 1; i <= n-1; i++){
            int x, y, distance; cin >> x >> y >> distance;
            adj[x].push_back({y, distance});
            adj[y].push_back({x, distance});
        }
        dfs(1);
        dinh1 = tmp.second;
        dfs(dinh1);
        cout << tmp.first << endl;
    }
    return 0;
}
