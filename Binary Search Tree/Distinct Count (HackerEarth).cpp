#include<bits/stdc++.h>
using namespace std;
#define MAX 13005

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
    {
        int n, x; cin >> n >> x;
        set<int> s;
        for(int i = 1; i <= n; i++){
            int tmp; cin >> tmp;
            s.insert(tmp);
        }
        if(s.size() > x) cout << "Average" << endl;
        else if(s.size() == x) cout << "Good" << endl;
        else cout << "Bad" << endl;
    }
    return 0;
}
