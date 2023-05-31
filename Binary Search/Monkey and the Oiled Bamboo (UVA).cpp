#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
int T, n, a[MAX];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    for(int id = 1; id <= T; id++)
    {
        cin >> n;
        int ans = 0, now = 0;
        a[0] = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] - a[i-1] > ans){
                ans = a[i] - a[i-1];
                now = ans - 1;
                continue;
            }
            if(a[i] - a[i-1] > now){
                ans++;
                now = ans;
            }
            else if(a[i] - a[i-1] == now) now--;
        }
        cout << "Case " << id << ": " << ans << endl;
    }
    return 0;
}
