#include<bits/stdc++.h>
using namespace std;
#define MAX 50005
using ll = long long;

int main(){
    int n; cin >> n;
    ll a[MAX];
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[0] = 0;
    a[n+1] = LONG_MAX;
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
        ll x; cin >> x;
        int l = 0, r = n+1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(a[mid] > x){
                r = mid;
            }
            else if(a[mid] == x){
                r = mid;
                break;
            }
            else{
                l = mid + 1;
            }
        }
        l = r - 1;
        while(a[l] == x) l--;
        while(a[r] == x) r++;
        if(l == 0) cout << "X ";
        else cout << a[l] << " ";
        if(r == n+1) cout << "X" << endl;
        else cout << a[r] << endl;
    }
    return 0;
}
