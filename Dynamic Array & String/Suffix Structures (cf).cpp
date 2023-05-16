#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, t; cin >> s >> t;
    map<char, int> cnt;
    bool ok = true;
    for(auto x : s) cnt[x]++;
    for(auto x : t){
        cnt[x]--;
        if(cnt[x] < 0){
            ok = false;
            break;
        }
    }
    if(!ok){
        cout << "need tree";
        return 0;
    }
    int x = 0, y = 0;
    while(x < s.size() && y < t.size()){
        if(s[x] == t[y]) y++;
        x++;
    }
    if(y == t.size()){
        cout << "automaton";
        return 0;
    }
    if(s.size() == t.size()) cout << "array";
    else cout << "both";
    return 0;
}
