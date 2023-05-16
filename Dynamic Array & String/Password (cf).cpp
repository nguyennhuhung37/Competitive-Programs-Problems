#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k; cin >> n >> k;
    int cnt[101] = {0};
    while(n--){
        string s; cin >> s;
        cnt[s.size()]++;
    }
    string key; cin >> key;
    int tmp = key.size(), dem = 0;
    for(int i = 1; i < tmp; i++){
        dem += cnt[i];
    }
    cout << (dem + 1) + (dem / k) * 5 << " ";
    cout << (dem + cnt[tmp]) + ((dem + cnt[tmp] - 1) / k) * 5;
    return 0;
}
