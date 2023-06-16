#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

int n, a[MAX], b[MAX], c[MAX], max_a[MAX], max_b[MAX], max_c[MAX];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
    max_a[0] = 0; max_b[0] = 0; max_c[0] = 0;
    for(int i = 1; i <= n; i++){
        max_a[i] = max(max_b[i-1], max_c[i-1]) + a[i];
        max_b[i] = max(max_a[i-1], max_c[i-1]) + b[i];
        max_c[i] = max(max_a[i-1], max_b[i-1]) + c[i];
    }
    int res = 0;
    res = max(res, max_a[n]);
    res = max(res, max_b[n]);
    res = max(res, max_c[n]);
    cout << res;
    return 0;
}
