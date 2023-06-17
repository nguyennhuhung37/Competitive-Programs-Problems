#include <bits/stdc++.h>
using namespace std;
const int MAX_K = 100005;

int f[MAX_K];
int a[105];
int n, k;

int main () {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      if (i >= a[j] && f[i - a[j]] == 0) {
        f[i] = 1;
        break;
      }
    }
  }
  for(int i = 1; i <= k; i++) cout << f[i] << " ";
  cout << (f[k] == 1 ? "First" : "Second");
  return 0;
}
