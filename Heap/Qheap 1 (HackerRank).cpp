#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define iii pair<int, ii>
void solve()
{
    priority_queue<int, vector<int>, greater<int>> pq, tmp;
    int q; cin >> q;
    while(q--)
    {
        int kt; cin >> kt;
        if(kt == 1){
            int x; cin >> x;
            pq.push(x);
        }
        else if(kt == 2){
            int x; cin >> x;
            tmp.push(x);
        }
        else if(kt == 3){
            while(!tmp.empty() && pq.top() == tmp.top()){
                pq.pop();
                tmp.pop();
            }
            cout << pq.top() << endl;
        }
    }
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
