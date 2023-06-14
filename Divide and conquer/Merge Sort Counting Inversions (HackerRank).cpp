#include <stdio.h>
#include <vector>

using namespace std;
const int MAX_N = 100005;
const int inf = 10000007;
int numTest;
vector <int> a;
int n;

long long countInverse(int l, int r) {
  if (l >= r) {
    return 0LL;
  }
  int mid = (l + r) / 2;
  long long numInverse = 0LL;
  numInverse += countInverse(l, mid);
  numInverse += countInverse(mid + 1, r);
  vector <int> firstArray, secondArray;
  for (int i = l; i <= mid; i++) {
    firstArray.push_back(a[i]);
  }
  firstArray.push_back(inf);
  int szFirst = (int) firstArray.size() - 1;
  for (int i = mid + 1; i <= r; i++) {
    secondArray.push_back(a[i]);
  }
  secondArray.push_back(inf);
  int szSecond = (int) secondArray.size() - 1;
  vector <int> mergedArray;
  int firstPoint = 0, secondPoint = 0;
  while (firstPoint < szFirst || secondPoint < szSecond) {
    if (firstArray[firstPoint] <= secondArray[secondPoint]) {
      mergedArray.push_back(firstArray[firstPoint]);
      firstPoint++;
    }
    else {
      mergedArray.push_back(secondArray[secondPoint]);
      numInverse += szFirst - firstPoint;
      secondPoint++;
    }
  }
  for (int i = l; i <= r; i++) {
    a[i] = mergedArray[i - l];
  }
  return numInverse;
}

void solve() {
  scanf("%d", &numTest);
  for (int testCase = 1; testCase <= numTest; testCase++) {
    a.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      a.push_back(x);
    }
    long long res = countInverse(0, n - 1);
    printf("%lld\n", res);
  }
}

int main () {
  solve();
  return 0;
}
