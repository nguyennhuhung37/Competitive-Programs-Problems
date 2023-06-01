#include<bits/stdc++.h>
using namespace std;

int t, n, m;
int main(){
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        set<string> s;
        for(int i = 1; i <= n; i++){
            string tmp; cin >> tmp;
            s.insert(tmp);
        }
        for(int i = 1; i <= m; i++){
            string tmp; cin >> tmp;
            if(s.find(tmp) == s.end()){
                cout << "NO" << endl;
            }
            else cout << "YES" << endl;
            s.insert(tmp);
        }
    }
    return 0;
}
