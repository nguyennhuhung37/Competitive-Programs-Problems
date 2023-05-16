#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        stack<char> st;
        for(auto x : s){
            if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^') st.push(x);
            else if(x == ')'){
                cout << st.top();
                st.pop();
            }
            else if(x != '(') cout << x;
        }
        cout << endl;
    }
    return 0;
}
