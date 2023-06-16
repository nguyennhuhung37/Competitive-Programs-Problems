#include<bits/stdc++.h>
using namespace std;

string s, t;
int a[1001][1001];

int main(){
    for(int i = 0; i <= 1000; i++){
        a[i][0] = 0;
        a[0][i] = 0;
    }
    cin >> s >> t;
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= s.size(); j++){
            if(s[i-1] == t[j-1]){
                a[i][j] = a[i-1][j-1] + 1;
            }
            else{
                a[i][j] = max(a[i-1][j], a[i][j-1]);
            }
        }
    }
    cout << a[s.size()][t.size()];
    return 0;
}
