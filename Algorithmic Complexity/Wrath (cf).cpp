#include<bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
int main()
{
    int n; cin >> n;
    vector<int> v;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int tmp, ans = 0;
    for(int i = n-1; i >= 0; i--)
    {
        tmp = i - v[i];
        ans++;
        if(tmp <= 0){
            cout << ans; return 0;
        }
        while(i > tmp || v[i]){
            tmp = min(i - v[i], tmp);
            if(tmp <= 0){
                cout << ans; return 0;
            }
            i--;
        }
    }
    cout << ans;
    return 0;
}
