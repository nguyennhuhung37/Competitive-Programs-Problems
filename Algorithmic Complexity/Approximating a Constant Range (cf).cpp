#include<bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
int main()
{
    int n; cin >> n;
    int a[100001];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int cnt[100005] = {0};
    int l = 1, ans = 0;
    for(int i = 1; i <= n; i++){
        cnt[a[i]]++;
        while(cnt[max(a[i]-2, 0)] != 0 || cnt[a[i]+2] != 0){
            cnt[a[l]]--;
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}
