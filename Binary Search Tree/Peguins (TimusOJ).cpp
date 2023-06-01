#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    cin.ignore();
    map<string, int> cnt;
    for(int i = 1; i <= n; i++){
        string tmp;
        getline(cin, tmp);
        cnt[tmp]++;
    }
    int tmp = 0;
    string ans;
    for(auto x : cnt){
        if(x.second > tmp){
            tmp = x.second;
            ans = x.first;
        }
    }
    cout << ans;
    return 0;
}
