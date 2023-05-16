#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
int main()
{
    int n, x; cin >> n >> x;
    ll a[100001];
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += x * a[i];
        x = max(1, x-1);
    }
    cout << ans;
    return 0;
}
