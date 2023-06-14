#include <iostream>

using namespace std;
const int MAX_N = 100005;
const int inf = -1000000007;
int a[MAX_N];
int n, numTest;

struct element {
  int sumLeft, sumRight;
  int maxSum;
};

element calcSubArray(int l, int r) {
  if (l == r) {
    return ((element) {a[l], a[l], a[l]});
  }
  int mid = (l + r) / 2;
  element firstSubArray = calcSubArray(l, mid);
  element secondSubArray = calcSubArray(mid + 1, r);
  int sum = 0;
  int maxLeft = inf;
  int maxRight = inf;
  for (int i = l; i <= r; i++) {
    sum += a[i];
    if (maxLeft < sum) {
      maxLeft = sum;
    }
  }
  sum = 0;
  for (int i = r; i >= l; i--) {
    sum += a[i];
    if (maxRight < sum) {
      maxRight = sum;
    }
  }
  element subArray;
  subArray.sumLeft = maxLeft;
  subArray.sumRight = maxRight;
  subArray.maxSum = inf;
  if (subArray.maxSum < firstSubArray.maxSum) {
    subArray.maxSum = firstSubArray.maxSum;
  }
  if (subArray.maxSum < secondSubArray.maxSum) {
    subArray.maxSum = secondSubArray.maxSum;
  }
  if (subArray.maxSum < firstSubArray.sumRight + secondSubArray.sumLeft) {
    subArray.maxSum = firstSubArray.sumRight + secondSubArray.sumLeft;
  }
  return subArray;
}

int main () {
  scanf("%d", &numTest);
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int maxElement = -10007;
    scanf("%d", &n);
    int sumSubSequence = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (maxElement < a[i]) {
        maxElement = a[i];
      }
      if (a[i] >= 0) {
        sumSubSequence += a[i];
      }
    }
    if (maxElement < 0) {
      sumSubSequence = maxElement;
    }
    element sumSubArray = calcSubArray(1, n);
    printf("%d %d\n", sumSubArray.maxSum, sumSubSequence);
  }
  return 0;
}
