#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n; cin >> n;
    set<ll> s;
    ll ans = LONG_MAX;
    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        auto it = s.upper_bound(x);
        if(it != s.end()){
            ans = min(ans, *it - x);
        }
        s.insert(x);
    }
    cout << ans;
    return 0;
}
