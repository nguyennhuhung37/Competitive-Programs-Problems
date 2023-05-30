#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
using ll = long long;

ll n, m, ans = 0;
ll a[MAX];
bool BinarySearch(int i)
{
    int l = i + 1, r = n;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(a[mid] + a[i] == m){
            return true;
        }
        else if(a[mid] + a[i] > m){
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return false;
}
int main(){
    int t; cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++){
            ans += BinarySearch(i);
        }
        cout << ans << endl;
    }
}
