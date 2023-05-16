#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0; // Biến đếm số lượng phần tử bằng 0

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt += (x == 0); // Tăng cnt nếu x bằng 0
    }

    if (cnt <= 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
