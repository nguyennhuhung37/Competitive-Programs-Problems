#include<bits/stdc++.h>
using namespace std;
const int N = 1003, LG = 9;

int m, n;
int a[N][N];
int lg[N];
int prf[N][N];
int st[LG+1][N][LG+1][N];
void preprocess(){
    lg[1] = 0;
    for(int i = 2; i <= N; i++){
        lg[i] = lg[i / 2] + 1;
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            prf[i][j] = prf[i-1][j] + prf[i][j-1] - prf[i-1][j-1] + a[i][j];
        }
    }
    for(int k = 0; k <= LG; k++){
        for(int i = 1; i + (1 << k) - 1 <= m; i++){
            for(int l = 0; l <= LG; l++){
                for(int j = 1; j + (1 << l) - 1 <= n; j++){
                    if(k == 0){
                        if(l == 0){
                            st[0][i][0][j] = a[i][j];
                        }
                        else{
                            st[0][i][l][j] = max(st[0][i][l-1][j], st[0][i][l-1][j + (1 << l-1)]);
                        }
                    }
                    else{
                        st[k][i][l][j] = max(st[k-1][i][l][j], st[k-1][i + (1 << k-1)][l][j]);
                    }
                }
            }
        }
    }
}

int getSum(int x, int y, int a, int b){
    return prf[a][b] - prf[x-1][b] - prf[a][y-1] + prf[x-1][y-1];
}

int getMax(int x, int y, int a, int b){
    int k = lg[a - x + 1];
    int l = lg[b - y + 1];
    return max({ st[k][x][l][y],
                 st[k][x][l][b - (1 << l) + 1],
                 st[k][a - (1 << k) + 1][l][y],
                 st[k][a - (1 << k) + 1][l][b - (1 << l) + 1]});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    preprocess();
    int q; cin >> q;
    while(q--)
    {
        int x, y; cin >> x >> y;
        int ans = 1e9;
        for(int i = x; i <= m; i++){
            for(int j = y; j <= n; j++){
                ans = min(ans, getMax(i - x + 1, j - y + 1, i, j) * x * y - getSum(i - x + 1, j - y + 1, i, j));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
