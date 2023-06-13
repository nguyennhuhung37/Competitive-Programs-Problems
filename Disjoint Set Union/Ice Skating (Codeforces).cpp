#include<bits/stdc++.h>
using namespace std;
#define MAX 105

int parent[MAX], res;

int findSet(int u){
    if(parent[u] != u){
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

void unionSet(int u, int v){
    int up = findSet(u);
    int vp = findSet(v);
    if(up == vp){
        return;
    }
    else{
        parent[up] = vp;
        res--;
    }
}

int main(){
    int n; cin >> n;
    pair<int, int> a[MAX];
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    res = n-1;
    for(int i = 1; i <= n; i++) parent[i] = i;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(a[i].first == a[j].first || a[i].second == a[j].second){
                unionSet(i, j);
            }
        }
    }
    cout << res;
    return 0;
}
