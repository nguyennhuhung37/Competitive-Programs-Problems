#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll p, c;
int n = 1;
int main(){
    while(cin >> p >> c)
    {
        if(!p) break;
        cout << "Case " << n << ":" << endl; n++;
        queue<ll> q;
        for(ll i = 1; i <= min((ll) 1000, p); i++) q.push(i);
        while(c--)
        {
            char lenh; cin >> lenh;
            if(lenh == 'N') {
                cout << q.front() << endl;
                ll tmp = q.front();
                q.pop();
                q.push(tmp);
            }
            else if(lenh == 'E'){
                ll x; cin >> x;
                queue<ll> q_tmp;
                q_tmp.push(x);
                while(!q.empty() && q_tmp.size() <= 1000){
                    if(q.front() != x) q_tmp.push(q.front());
                    q.pop();
                }
                swap(q, q_tmp);
            }
        }
    }
    return 0;
}
