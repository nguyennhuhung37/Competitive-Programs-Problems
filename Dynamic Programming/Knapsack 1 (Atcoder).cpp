#include<bits/stdc++.h>
using namespace std;
#define MAX_N 105
#define MAX_W 100005

int n, w;
int weight[MAX_N], value[MAX_N];
long long f[MAX_N][MAX_W];

int main(){
    cin >> n >> w;
    for(int i = 1; i <= n; i++){
        cin >> weight[i] >> value[i];
    }
    for(int i = 0; i <= n; i++) f[i][0] = 0;
    for(int j = 0; j <= w; j++) f[0][j] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            f[i][j] = f[i-1][j];
            if(weight[i] <= j){
                f[i][j] = max(f[i][j], f[i-1][j - weight[i]] + value[i]);
            }
        }
    }
    cout << f[n][w];
    return 0;
}
