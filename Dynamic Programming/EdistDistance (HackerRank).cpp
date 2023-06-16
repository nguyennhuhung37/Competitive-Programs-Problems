#include<bits/stdc++.h>
using namespace std;

int n;
string s, t;
int f[2000][2000];

int main(){
    cin >> n;
    while(n--){
    cin >> s >> t;
    for(int i = 0; i <= s.size(); i++) f[i][0] = i;
    for(int j = 0; j <= t.size(); j++) f[0][j] = j;
    for(int i = 1; i <= s.size(); i++){
        for(int j = 1; j <= t.size(); j++){
            if(s[i-1] == t[j-1]){
                f[i][j] = f[i-1][j-1];
            }
            else{
                f[i][j] = f[i-1][j-1] + 1;
                f[i][j] = min(f[i][j], f[i][j-1] + 1);
                f[i][j] = min(f[i][j], f[i-1][j] + 1);
            }
        }
    }
    cout << f[s.size()][t.size()] << endl;
    }
    return 0;
}
