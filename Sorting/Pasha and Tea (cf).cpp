#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define fi first
#define se second
bool comp(const ii &a, const ii &b)
{
    return a > b;
}
int main()
{
    int n, w; cin >> n >> w;
    float a[200001];
    for(int i = 1; i <= 2*n; i++) cin >> a[i];
    sort(a + 1, a + n*2 + 1);
    float ans = min(a[1], a[n+1]/2) * 3 * n;
    cout << setprecision(2) << fixed << min(ans, (float)w);
    return 0;
}
