#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int ans = 0;
    while(n--)
    {
        int x; cin >> x;
        ans += 15;
        if(ans >= 90) {cout << 90; return 0;}
        if(x > ans) {cout << ans; return 0;}
        else ans = x;
    }
    cout << min(90,ans + 15);
    return 0;
}
