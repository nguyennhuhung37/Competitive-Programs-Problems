#include<bits/stdc++.h>
using namespace std;
#define MAX 55
const int inf = 1e9;

int T;
string s[MAX];
int dist[MAX][MAX];

void FloydWarshall(){
    for(int k = 0; k < s[0].size(); k++){
        for(int i = 0; i < s[0].size(); i++){
            for(int j = 0; j < s[0].size(); j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> s[0];
        for(int i = 1; i < s[0].size(); i++) cin >> s[i];
        for(int i = 0; i < s[0].size(); i++){
        for(int j = 0; j < s[0].size(); j++){
            if(i == j) dist[i][j] = 0;
            else{
                if(s[i][j] == 'Y') dist[i][j] = 1;
                else dist[i][j] = inf;
            }
        }
        }
        FloydWarshall();
        int nfriends = 0, index = 0;
        for(int i = 0; i < s[0].size(); i++){
            int cnt = 0;
            for(int j = 0; j < s[0].size(); j++){
                if(dist[i][j] == 2) cnt++;
            }
            if(cnt > nfriends){
                nfriends = cnt;
                index = i;
            }
        }
        cout << index << " " << nfriends << endl;
    }
    return 0;
}
