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
    int n; cin >> n;
    int a[100001];
    ii copy_a[100001];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        copy_a[i] = {a[i], i};
    }
    sort(copy_a + 1, copy_a + n + 1, comp);
    int x = 1;
    for(int i = 1; i <= n; i++){
        if(copy_a[i].first != copy_a[i-1].first) x = i;
        a[copy_a[i].se] = x;
    }
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}
