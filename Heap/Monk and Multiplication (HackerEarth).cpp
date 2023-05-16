#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define iii pair<int, ii>
void solve()
{
    int n; cin >> n;
    priority_queue<ll> pq;
    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        pq.push(x);
        if(i == 1 || i == 2){
            cout << -1 << endl;
        }
        else{
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            ll c = pq.top();
            cout << a * b * c << endl;
            pq.push(b); pq.push(a);
        }
    }
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
