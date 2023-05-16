#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define iii pair<int, ii>

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    ll ans = 0;
    priority_queue<ll> max_h;
    priority_queue<ll, vector<ll>, greater<ll> > min_h;
    while(n--)
    {
        int k; cin >> k;
        while(k--){
            ll x; cin >> x;
            max_h.push(x); min_h.push(x);
        }
        ll tmp = max_h.top() - min_h.top();
        ans += tmp;
        max_h.pop(); min_h.pop();
        if(max_h.top() == min_h.top()){
            tmp = max_h.top();
            max_h = priority_queue<ll>();
            min_h = priority_queue<ll, vector<ll>, greater<ll> >();
            max_h.push(tmp); min_h.push(tmp);
        }
        else if(max_h.top() < min_h.top()){
            max_h = priority_queue<ll>();
            min_h = priority_queue<ll, vector<ll>, greater<ll> >();
        }
    }
    cout << ans;
    return 0;
}
