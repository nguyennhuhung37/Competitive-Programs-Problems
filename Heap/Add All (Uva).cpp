#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define iii pair<int, ii>
int n;
void solve()
{
    while(cin >> n)
    {
        if(n == 0) break;
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        for(int i = 1; i <= n; i++){
            ll x; cin >> x;
            pq.push(x);
        }
        ll ans = 0;
        while(pq.size() >= 2){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        cout << ans << endl;
    }
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
