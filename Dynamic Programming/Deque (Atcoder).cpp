#include<bits/stdc++.h>
using namespace std;
#define MAX 3005

int n;
long long a[MAX];
long long f[MAX][MAX][2];
bool check[MAX][MAX][2];

long long solve(int l, int r, int type){
    if(check[l][r][type]){
        return f[l][r][type];
    }
    if(type == 0){
        if(l == r) f[l][r][type] = a[l];
        else f[l][r][type] = max(a[l] + solve(l+1, r, 1 - type), a[r] + solve(l, r-1, 1 - type));
    }
    else{
        if(l == r) f[l][r][type] = -a[l];
        else f[l][r][type] = min(-a[l] + solve(l+1, r, 1 - type), -a[r] + solve(l, r-1, 1 - type));
    }
    check[l][r][type] = true;
    return f[l][r][type];
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << solve(1, n, 0);
    return 0;
}
