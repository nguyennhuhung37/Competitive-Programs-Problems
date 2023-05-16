#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define fi first
#define se second
void solve()
{
    int n; cin >> n;
    int a[1001];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = n, x = 0, y = 0, i = n;
    while(l <= r){
        if((n - i) % 2 == 0) x += max(a[l], a[r]);
        else y += max(a[l], a[r]);
        if(a[l] <= a[r]) r--;
        else l++;
        i--;
    }
    cout << x << " " << y;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
