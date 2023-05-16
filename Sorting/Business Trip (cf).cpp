#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define fi first
#define se second
bool comp(const ii &a, const ii &b)
{
    return a > b;
}
int main()
{
    int k; cin >> k;
    if(k == 0) {
        cout << 0; return 0;
    }
    int a[13];
    for(int i = 1; i <= 12; i++) cin >> a[i];
    sort(a + 1, a + 13, greater<int>());
    int sum = 0;
    for(int i = 1; i <= 12; i++){
        sum += a[i];
        if(sum >= k){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
