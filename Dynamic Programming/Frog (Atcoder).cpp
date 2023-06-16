#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int h[n+1], ans[n+1];
    for(int i = 1; i <= n; i++) cin >> h[i];
    ans[1] = 0; ans[2] = abs(h[2] - h[1]);
    for(int i = 3; i <= n; i++){
        ans[i] = min(ans[i-2] + abs(h[i] - h[i-2]), ans[i-1] + abs(h[i] - h[i-1]));
    }
    cout << ans[n];
    return 0;
}
