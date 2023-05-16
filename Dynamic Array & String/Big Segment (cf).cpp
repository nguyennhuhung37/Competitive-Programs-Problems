#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int l, r; cin >> l >> r;
    int ans = 1;
    for(int i = 2; i <= n; i++){
        int x, y; cin >> x >> y;
        if(x < l || r < y) ans = -1;
        l = min(l, x); r = max(r, y);
        if(x == l && y == r) ans = i;
    }
    cout << ans;
    return 0;
}
