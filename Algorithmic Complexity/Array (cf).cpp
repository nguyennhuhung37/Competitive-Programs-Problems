#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k; cin >> n >> k;
    int a[100001];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 1;
    int cnt[100001] = {0}, dem = 0;
    while(dem < k && r <= n){
        if(!cnt[a[r]]) dem++;
        cnt[a[r]]++;
        r++;
    }
    r--;
    if(dem < k){
        cout << "-1 -1";
        return 0;
    }
    while(cnt[a[l]] > 1){
        cnt[a[l]]--;
        l++;
    }
    cout << l << " " << r;
    return 0;
}
