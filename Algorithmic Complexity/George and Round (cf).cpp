#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    int a[100001], b[100001];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    int x = 1, y = 1;
    while(x <= n && y <= m)
    {
        if(a[x] <= b[y]) x++;
        y++;
    }
    cout << n + 1 - x;
    return 0;
}
