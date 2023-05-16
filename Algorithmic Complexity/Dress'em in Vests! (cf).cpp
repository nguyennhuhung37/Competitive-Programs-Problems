#include<bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
int main()
{
    int n, m, x, y; cin >> n >> m >> x >> y;
    int a[100001], b[100001];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    vector<ii> v;
    int l = 1, r = 1;
    while(l <= n && r <= m){
        if(a[l] >= b[r] - y && a[l] <= b[r] + x){
            v.push_back({l, r});
            l++; r++;
        }
        else if(a[l] < b[r] - y) l++;
        else r++;
    }
    cout << v.size() << endl;
    for(auto x : v)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}
