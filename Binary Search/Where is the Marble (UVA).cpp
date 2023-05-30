#include<bits/stdc++.h>
using namespace std;

int n, q, a[10005], id;
void BinarySearch(int x)
{
    int l = 1, r = n;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(a[mid] == x){
            while(a[mid-1] == x) mid--;
            cout << x << " found at " << mid << endl;
            return;
        }
        else if(a[mid] > x){
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << x << " not found" << endl;
}
int main(){
    id = 1;
    while(cin >> n >> q && n != 0)
    {
        cout << "CASE# " << id << ":" << endl;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= q; i++){
            int x; cin >> x;
            BinarySearch(x);
        }
        id++;
    }
    return 0;
}
