#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        if(s[0] == '>'){
            cout << 0 << endl;
            continue;
        }
        int ans = 0, m = 0, t = 0;
        for(auto x : s){
            if(x == '<'){
                m++;
                t++;
            }
            else{
                if(t == 0){
                    m = 0;
                }
                else{
                    t--;
                    ans = max(ans, m - t);
                }
            }
        }
        if(t > 0) cout << 0 << endl;
        else cout << 2 * ans << endl;
    }
    return 0;
}
