#include <bits/stdc++.h>

using namespace std;

int parent[26];

int test , n , u , v , ans;
char c;
string s;

void init(int u) {
    parent[u] = u;
}

int findSet(int u) {
    while (u != parent[u]) u = parent[u];

    return u;
}

int unionSet(int u , int v){
    int up = findSet(u); int vp = findSet(v);

    parent[vp] = up;
}

int main() {
    scanf("%d\n\n" , &test);

    for(int t = 1; t <= test; t++) {
        getline(cin,s);
        n = s[0] - 'A' + 1;

        ans = n;
        for (int i = 0; i < n; i++) init(i);

        while(1) {
            if (!getline(cin , s) || s.empty()) break;

            u = s[0] - 'A'; v = s[1] - 'A';

            int up = findSet(u); int vp = findSet(v);

            if (up != vp) {
                ans--;
                unionSet(u , v);
            }
        }

        if (t != 1) printf("\n");
        printf("%d\n" , ans);
    }

    return 0;
}
