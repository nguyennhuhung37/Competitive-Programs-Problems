#include<bits/stdc++.h>
using namespace std;

char chance(char x){
    if('a' <= x && x <= 'z') return x - 32;
    else return x + 32;
}
int main(){
    string s, t; cin >> s >> t;
    map<char, int> cnt_s, cnt_t;
    for(auto x : s){
        cnt_s[x]++;
    }
    for(auto x : t){
        cnt_t[x]++;
    }
    int yay = 0, whoobs = 0;
    for(char x = 'a'; x <= 'z'; x++){
        int tmp = min(cnt_s[x], cnt_t[x]);
        yay += tmp;
        cnt_s[x] -= tmp;
        cnt_t[x] -= tmp;
        tmp = min(cnt_s[chance(x)], cnt_t[chance(x)]);
        yay += tmp;
        cnt_s[chance(x)] -= tmp;
        cnt_t[chance(x)] -= tmp;
        tmp = min(cnt_s[x], cnt_t[chance(x)]) + min(cnt_s[chance(x)], cnt_t[x]);
        whoobs += tmp;
    }
    cout << yay << " " << whoobs;
    return 0;
}
