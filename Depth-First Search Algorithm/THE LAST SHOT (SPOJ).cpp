#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define iii pair<int, ii>
int n, m, cnt = 1;
vector<int> adj[10001];
bool visited[10001];
void dfs(int i)
{
    for(int i = 1; i <= n; i++) visited[i] = false;
    stack<int> st;
    st.push(i);
    visited[i] = true;
    while(!st.empty()){
        int v = st.top();
        st.pop();
        for(auto x : adj[v]){
            if(!visited[x]){
                visited[x] = true;
                cnt++;
                st.push(x);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    while(m--)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cnt = 1;
        dfs(i);
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}
