#include<bits/stdc++.h>
using namespace std;
#define MAX 405

int n;
long long a[MAX], f[MAX][MAX], prefix[MAX];
bool check[MAX][MAX];

long long solve(int l, int r){
    cout << l << " " << r << endl;
    if(check[l][r]){
        return f[l][r];
    }
    if(l == r){
        f[l][r] = 0;
    }
    else{
        long long tmp = LONG_MAX;
        for(int i = l; i < r; i++){
            tmp = min(tmp, prefix[r] - prefix[l-1] + solve(l, i) + solve(i + 1, r));
        }
        f[l][r] = tmp;
    }
    check[l][r] = true;
    return f[l][r];
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    prefix[0] = 0;
    for(int i = 1; i <= n ;i++) prefix[i] = prefix[i-1] + a[i];
    cout << solve(1, n);
    return 0;
}
