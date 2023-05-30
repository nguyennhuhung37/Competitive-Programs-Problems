#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll m;
vector<ll> v;

bool Check(ll x)
{
    ll sum = 0;
    for(int i = 0; i < n ; i++){
        sum += max(0ll, v[i] - x);
    }
    return sum >= m;
}
int main(){
    cin >> n >> m;
    ll Max = 0;
    for(int i = 1; i <= n; i++){
        ll x; cin >> x;
        v.push_back(x);
        Max = max(Max, x);
    }
    ll l = 0, r = Max;
    while(l < r)
    {
        ll mid = l + (r - l + 1) / 2;
        if(Check(mid)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}
