#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    int tmp = s.size() - 1;
    while(s[tmp] == 'z')
    {
        s[tmp] = 'a';
        tmp--;
    }
    s[tmp]++;
    if(s < t) cout << s;
    else cout << "No such string";
    return 0;
}
