#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define iii pair<ii, int>
void solve()
{
    int n; cin >> n;
    priority_queue<iii> pq;
    while(n--)
    {
        int id, z_score, p, l, c, s; cin >> id >> z_score >> p >> l >> c >> s;
        int score = p * 50 + l * 5 +  c * 10 + s * 20;
        pq.push({{score - z_score, id}, score});
    }
    for(int i = 1; i <= 5; i++){
        iii tmp = pq.top(); pq.pop();
        cout << tmp.first.second << " " << tmp.second << endl;
    }
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
