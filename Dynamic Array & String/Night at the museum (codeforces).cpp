#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s; cin >> s;
    char tmp = 'a';
    int ans = 0;
    for(auto x : s){
        ans += min(abs(tmp - x), 26 - abs(tmp - x));
        tmp = x;
    }
    cout << ans;
    return 0;
}
