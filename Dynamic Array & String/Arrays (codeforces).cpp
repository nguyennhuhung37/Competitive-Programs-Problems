#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x, y; cin >> x >> y;
    int k, m; cin >> k >> m;
    int a[100001], b[100001];
    for(int i = 1; i <= x; i++) cin >> a[i];
    for(int i = 1; i <= y; i++) cin >> b[i];
    if(a[k] < b[y-m+1]) cout << "YES";
    else cout << "NO";
    return 0;
}
