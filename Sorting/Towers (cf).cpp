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
    int n; cin >> n;
    int a[1001];
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int chieu_cao = 1, so_thap = n, h = 1;
    for(int i = 2; i <= n; i++){
        if(a[i] == a[i-1]){
            h++;
            so_thap--;
        }
        else h = 1;
        chieu_cao = max(chieu_cao, h);
    }
    cout << chieu_cao << " " << so_thap;
    return 0;
}
