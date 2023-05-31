#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, s; cin >> n >> s;
    set<pair<double, int> > save;
    for(int i = 1; i <= n; i++){
        int x, y, k; cin >> x >> y >> k;
        double rad = sqrt(x * x + y * y); //rad : radius : bán kính
        save.insert({rad, k});
    }
    for(auto x : save){
        s += x.second;
        if(s >= 1000000){
            cout << setprecision(10) << x.first;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
