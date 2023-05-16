#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
int main(){
    while(cin >> n)
    {
        if(n == 0) break;
        int a[n+2], tmp = 1;
        for(int i = 1; i <= n; i++) cin >> a[i];
        stack<int> st;
        for(int i = 1; i <= n; i++){
            while(!st.empty() && tmp == st.top()){
                tmp++;
                st.pop();
            }
            if(tmp == a[i]){
                tmp++;
                continue;
            }
            else st.push(a[i]);
        }
        while(!st.empty() && tmp == st.top()){
                tmp++;
                st.pop();
        }
        if(tmp == n+1) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
