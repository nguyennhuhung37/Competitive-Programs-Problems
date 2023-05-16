#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

string s;
int n;
stack<int> st;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> s;
    n = s.size();
    s = '@' + s;

    for(int i = 1; i <= n; i++)
    {
        if(s[i] == 'C') st.push(12);
        if(s[i] == 'O') st.push(16);
        if(s[i] == 'H') st.push(1);
        if(s[i] >= '1' && s[i] <= '9')
        {
            int x = st.top();
            st.pop();
            st.push(x * (s[i] - '0'));
        }

        if(s[i] == '(') st.push(0);
        if(s[i] == ')')
        {
            int x = 0;
            while(st.top())
            {
                x += st.top();
                st.pop();
            }
            st.pop();
            st.push(x);
        }
    }

    int res = 0;

    while(st.size())
    {
        res += st.top();
        st.pop();
    }

    cout << res;
}
