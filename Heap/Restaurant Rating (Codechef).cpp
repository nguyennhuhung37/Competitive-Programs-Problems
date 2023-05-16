#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair<int, int>
#define iii pair<int, ii>
void solve()
{
    int n, type, nreviews = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > top3;
    priority_queue<int> rest;
    while(n--){
        cin >> type;
        if(type == 1){
            int x; cin >> x;
            nreviews++;
            if(!top3.empty() && top3.top() < x){
                rest.push(top3.top());
                top3.pop();
                top3.push(x);
            }
            else{
                rest.push(x);
            }
            if(nreviews % 3 == 0){
                top3.push(rest.top());
                rest.pop();
            }
        }
        else if(type == 2){
            if(top3.empty()) cout << "No reviews yet" << endl;
            else cout << top3.top() << endl;
        }
    }
}
int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
