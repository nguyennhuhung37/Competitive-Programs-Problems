#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, t; cin >> n >> t;
    int a[100001];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int sum = 0, l = 1, r = 1, ans = 0;
    while(r <= n){
        sum += a[r];
        while(sum > t){
            sum -= a[l];
            l++;
        }
        ans = max(ans, r - l +1);
        r++;
    }
    cout << ans;
    return 0;
}
