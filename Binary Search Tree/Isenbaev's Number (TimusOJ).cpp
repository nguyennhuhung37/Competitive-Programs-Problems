#include<bits/stdc++.h>
using namespace std;

int n;
map<string, int> cnt;
map<string, vector<string> > s;
void bfs(){
    queue<string> q;
    q.push("Isenbaev");
    cnt["Isenbaev"] = 0;
    while(!q.empty()){
        string u = q.front();
        q.pop();
        for(auto x : s[u]){
            if(x != "Isenbaev" && cnt[x] == 0){
                cnt[x] = cnt[u] + 1;
                q.push(x);
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        string x, y, z; cin >> x >> y >> z;
        cnt[x] = 0; cnt[y] = 0; cnt[z] = 0;
        s[x].push_back(y);
        s[x].push_back(z);
        s[y].push_back(x);
        s[y].push_back(z);
        s[z].push_back(x);
        s[z].push_back(y);
    }
    if(cnt.find("Isenbaev") != cnt.end() ) bfs();
    for(auto x : cnt){
        cout << x.first << " ";
        if(x.second == 0 && x.first != "Isenbaev") cout << "undefined" << endl;
        else cout << x.second << endl;
    }
    return 0;
}
