#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
int main()
{
    int n, x = 1, y = 1; cin >> n;
    int a[100001];
    bool ok = false;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        if(a[i] > a[i+1] && !ok){
            x = i;
            while(a[i] > a[i+1] && i < n) i++;
            y = i;
            sort(a + x, a + y + 1);
            ok = true;
        }
        if(a[i] > a[i+1] && ok){
            cout << "no";
            return 0;
        }
    }
    cout << "yes" << endl;
    cout << x << " " << y;
    return 0;
}
