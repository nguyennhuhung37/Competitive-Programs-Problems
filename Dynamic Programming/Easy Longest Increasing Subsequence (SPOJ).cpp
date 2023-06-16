#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans[n+1], res = 1;
    for(int i = 1; i <= n; i++) ans[i] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(a[j] < a[i]){
                ans[i] = max(ans[i], ans[j]+1);
            }
        }
        res = max(res, ans[i]);
    }
    cout << res;
    return 0;
}
