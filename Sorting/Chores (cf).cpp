#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
int main()
{
    int n, a, b; cin >> n >> a >> b;
    int v[2005];
    for(int i = 1 ; i <= n; i++) cin >> v[i];
    sort(v + 1, v + n + 1);
    cout << v[b+1] - v[b];
    return 0;
}
