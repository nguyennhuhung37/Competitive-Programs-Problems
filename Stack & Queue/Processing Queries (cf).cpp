#include<bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll n, b, hien_tai = 0, tiep_theo = 0; cin >> n >> b;
    queue<pair<ll, ll> > q;
    while(n--)
    {
        ll t, d; cin >> t >> d;
        if(t < hien_tai){
            if(q.empty() || q.size() < b){
                tiep_theo += d;
                cout << tiep_theo << " ";
                q.push({t, d});
            }
            else {
                cout << "-1 ";
            }
        }
        else{
            tiep_theo = max(tiep_theo, t) + d;
            cout << tiep_theo << " ";
            q.push({t, d});
            pair<ll, ll> v = q.front();
            q.pop();
            hien_tai = max(hien_tai, v.first) + v.second;
        }
    }
}
