#include <iostream>
#include <math.h>

using namespace std;
const int MAX_N = 105;
const int MAX_V = 100005;
const int inf = 1000000007;
int n, W;
int weight[MAX_N], value[MAX_N];
long long f[MAX_N][MAX_V];

void solve() {
  cin >> n >> W;
  int sum = 0;
  for(int i = 1; i <= n; i++){
    cin >> weight[i] >> value[i];
    sum += value[i];
  }
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= sum; j++){
        f[i][j] = inf;
    }
  }
  f[0][0] = 0;
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= sum; j++){
        if(f[i][j] == inf){
            continue;
        }
        f[i+1][j] = min(f[i+1][j], f[i][j]);
        if(f[i][j] + weight[i + 1] <= W){
            f[i+1][j + value[i+1]] = min(f[i+1][j+ value[i+1]], f[i][j] + weight[i+1]);
        }
    }
  }
  int res;
  for(int i = 0; i <= sum; i++){
    if(f[n][i] <= W){
        res = i;
    }
  }
  cout << res;
}

int main () {
  solve();
  return 0;
}
